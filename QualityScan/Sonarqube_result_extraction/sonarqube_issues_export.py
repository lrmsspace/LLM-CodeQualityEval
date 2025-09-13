import requests
import pandas as pd
import time
#拉取指定项目的所有问题（Issues），并根据严重性等级（BLOCKER、CRITICAL、MAJOR、MINOR、INFO）分别抓取，最终导出为 Excel 文件。

SONARQUBE_URL = "http://localhost:9000"
PROJECT_KEY = "Codeium_Java_new"     
AUTH_TOKEN = "sqp_2a09ab34f29a167f814861ae4be7f02086"       

SEVERITIES = ["BLOCKER", "CRITICAL", "MAJOR", "MINOR", "INFO"]
PAGE_SIZE = 500
SLEEP_TIME = 0.2

# === 拉取指定严重性等级的 issues ===
def fetch_issues_by_severity(severity):
    issues = []
    page = 1
    headers = {"Authorization": f"Bearer {AUTH_TOKEN}"} if AUTH_TOKEN else {}

    while True:
        print(f"🔎 Fetching severity={severity}, page={page}...")
        params = {
            "componentKeys": PROJECT_KEY,
            "severities": severity,
            "ps": PAGE_SIZE,
            "p": page
        }

        try:
            resp = requests.get(f"{SONARQUBE_URL}/api/issues/search", headers=headers, params=params)
            resp.raise_for_status()
            data = resp.json()
        except Exception as e:
            print(f"请求 {severity} 页 {page} 出错: {e}")
            break

        page_issues = data.get("issues", [])
        if not page_issues:
            break

        issues.extend(page_issues)

        total = data.get("total", 0)
        if page * PAGE_SIZE >= total:
            break

        page += 1
        time.sleep(SLEEP_TIME)

    return issues

def main():
    all_issues = []

    for severity in SEVERITIES:
        issues = fetch_issues_by_severity(severity)
        print(f"拉取 {severity} 级别问题数: {len(issues)}")
        all_issues.extend(issues)

    if not all_issues:
        print("未获取到任何问题")
        return

    df = pd.DataFrame([{
        "Key": i.get("key"),
        "Rule": i.get("rule"),
        "Severity": i.get("severity"),
        "Type": i.get("type"),
        "Component": i.get("component"),
        "Message": i.get("message"),
        "Line": i.get("line"),
        "Effort": i.get("effort"),
        "Creation Date": i.get("creationDate")
    } for i in all_issues])

    df.to_excel("Codeium_Java_issues_new.xlsx", index=False)
    print(f"\n 导出 {len(df)} 条记录到 sonarqube_issues_by_severity.xlsx")

    print("\n 各等级严重性统计：")
    print(df["Severity"].value_counts())

if __name__ == "__main__":
    main()
