import os
import subprocess

SRC_BASE = r"F:\JavaFile\TY\.java"
BIN_BASE = r"F:\JavaFile\TY\.class"
COMMON_BIN_DIR = os.path.join(BIN_BASE, "common")

COMMON_FILES = [
    os.path.join(SRC_BASE, "Node.java"),
    os.path.join(SRC_BASE, "ListNode.java"),
    os.path.join(SRC_BASE, "TreeNode.java"),
    os.path.join(SRC_BASE, "GuessGame.java"),
    os.path.join(SRC_BASE, "VersionControl.java"),
    os.path.join(SRC_BASE, "Pair.java")
]

LEVELS = ["Easy", "Medium", "Hard"]

# 先编译公共类
os.makedirs(COMMON_BIN_DIR, exist_ok=True)
print(f"\n正在编译公共类到：{COMMON_BIN_DIR}")
cmd_common = ["javac", "-d", COMMON_BIN_DIR] + COMMON_FILES
result = subprocess.run(cmd_common, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
if result.returncode != 0:
    print(f"❌ 公共类编译失败！\n{result.stderr}")
else:
    print(f"✔️ 公共类编译成功！")

# 编译每个 Java 文件，分别输出到独立子目录
for level in LEVELS:
    src_dir = os.path.join(SRC_BASE, level)
    bin_dir_base = os.path.join(BIN_BASE, level)
    os.makedirs(bin_dir_base, exist_ok=True)

    print(f"\n=== 正在处理：{level} ===")

    for file in os.listdir(src_dir):
        if file.endswith(".java"):
            file_path = os.path.join(src_dir, file)
            file_name_without_ext = os.path.splitext(file)[0]
            # 独立的输出目录
            file_output_dir = os.path.join(bin_dir_base, file_name_without_ext)
            os.makedirs(file_output_dir, exist_ok=True)

            cmd = ["javac", "-encoding", "UTF-8", "-cp", COMMON_BIN_DIR, "-d", file_output_dir, file_path]

            print(f"正在编译：{file}")
            result = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            if result.returncode != 0:
                print(f"❌ 编译失败：{file}\n{result.stderr}")
            else:
                print(f"✔️ 编译成功：{file}")


