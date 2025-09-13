import requests
import csv
import re

#从 SonarQube 项目中递归获取所有文件，提取认知复杂度和圈复杂度指标。

SONARQUBE_URL = "http://localhost:9000"        
PROJECT_KEY = "Tabnine_JavaScript_new"                  
AUTH_TOKEN = None                              
OUTPUT_FILE = "Tabnine_JavaScript_complexity.csv"   

headers = {}
if AUTH_TOKEN:
    headers["Authorization"] = f"Bearer {AUTH_TOKEN}"

def get_all_files(project_key):
    def recurse(component_key):
        page = 1
        page_size = 500
        files = []
        while True:
            params = {
                "component": component_key,
                "ps": page_size,
                "p": page
            }
            resp = requests.get(f"{SONARQUBE_URL}/api/components/tree", params=params, headers=headers)
            if resp.status_code != 200:
                print(f"❌ 请求失败：{resp.status_code}")
                print(resp.text)
                return []
            data = resp.json()
            for comp in data.get("components", []):
                if comp["qualifier"] == "FIL":
                    files.append(comp)
                elif comp["qualifier"] == "DIR":
                    files += recurse(comp["key"])
            if page * page_size >= data.get("paging", {}).get("total", 0):
                break
            page += 1
        return files

    print(f"正在递归抓取项目 {project_key} 下的所有文件...")
    all_files = recurse(project_key)
    print(f"原始抓取文件数（含重复路径）: {len(all_files)}")
    return all_files

# === 获取复杂度指标 ===
def get_complexity_metrics(file_key):
    metric_keys = "cognitive_complexity,complexity"
    params = {
        "component": file_key,
        "metricKeys": metric_keys
    }
    resp = requests.get(f"{SONARQUBE_URL}/api/measures/component", params=params, headers=headers)
    measures = resp.json().get("component", {}).get("measures", [])
    return {m["metric"]: m["value"] for m in measures}

# === 提取 index 和难度等级 ===
def extract_info(file_path):
    parts = file_path.split('/')
    difficulty = parts[0] if len(parts) > 1 else "Unknown"
    filename = parts[-1]
    match = re.search(r"(\d+)", filename)
    index = match.group(1) if match else ""
    return index, difficulty

def main():
    raw_files = get_all_files(PROJECT_KEY)

    # 使用 file["key"] 去重
    unique_files = {file["key"]: file for file in raw_files}.values()
    print(f"去重后唯一文件数: {len(unique_files)}")

    with open(OUTPUT_FILE, mode="w", newline="", encoding="utf-8") as f:
        writer = csv.writer(f)
        writer.writerow(["Index", "File", "Difficulty", "Cognitive Complexity", "Cyclomatic Complexity"])
        for file in unique_files:
            file_path = file["path"] if "path" in file else file["key"]
            index, difficulty = extract_info(file_path)
            metrics = get_complexity_metrics(file["key"])
            writer.writerow([
                index,
                file["name"],
                difficulty,
                metrics.get("cognitive_complexity", "0"),
                metrics.get("complexity", "0")
            ])
    print(f"导出完成，共 {len(unique_files)} 个文件，结果保存在 {OUTPUT_FILE}")

if __name__ == "__main__":
    main()
