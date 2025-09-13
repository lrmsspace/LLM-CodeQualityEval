#单独编译文件
import os
import subprocess
SRC_BASE = r"F:\JavaFile\TY\.java"
COMMON_FILES = [
     os.path.join(SRC_BASE, "Node.java"),
     os.path.join(SRC_BASE, "ListNode.java"),
     os.path.join(SRC_BASE, "TreeNode.java"),
     os.path.join(SRC_BASE, "GuessGame.java"),
     os.path.join(SRC_BASE, "VersionControl.java"),
     os.path.join(SRC_BASE, "Pair.java")
]
COMMON_BIN_DIR = r"F:\JavaFile\TY\.class\common"

# 单独编译的 Java 文件路径：
file_path = r"F:\JavaFile\new\Codeium\.java\Medium\2533-delete-nodes-from-linked-list-present-in-array.java"

output_dir = r"F:\JavaFile\new\Codeium\.class\Medium\2533-delete-nodes-from-linked-list-present-in-array"
os.makedirs(output_dir, exist_ok=True)

cmd = ["javac", "-encoding", "UTF-8", "-cp", COMMON_BIN_DIR, "-d", output_dir, file_path] + COMMON_FILES
print(f"正在编译：{file_path}")

result = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

if result.returncode != 0:
    print(f"❌ 编译失败：{file_path}\n{result.stderr}")
else:
    print(f"✔️ 编译成功，结果保存在：{output_dir}")

