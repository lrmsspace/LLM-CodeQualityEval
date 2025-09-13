import os

SRC_BASE = r"F:\JavaFile\new\Codeium\.java"
LEVELS = ["Easy", "Medium", "Hard"]

IMPORT_LINE = "import java.util.*;\n"

for level in LEVELS:
    src_dir = os.path.join(SRC_BASE, level)

    for file in os.listdir(src_dir):
        if file.endswith(".java"):
            file_path = os.path.join(src_dir, file)

            with open(file_path, "r", encoding="utf-8") as f:
                content = f.readlines()

            # 插入 import java.util.*; 
            new_content = []
            import_inserted = False
            for line in content:
                if not import_inserted and line.strip().startswith("class "):
                    new_content.append(IMPORT_LINE)
                    import_inserted = True
                new_content.append(line)

            with open(file_path, "w", encoding="utf-8") as f:
                f.writelines(new_content)

            print(f"✅ 已插入 import：{file}")
