import os
import re

directory = r'F:\JavaFile\Codeium\.java\Medium'

#要删除的文件
target_numbers = [
    '2407', '2421', '2429', '2446', '2473', '2496', '2567', '2591', '2611', '2616', '2646'
]

deleted_files = []
pattern = re.compile(r'^(\d+)-')  

for filename in os.listdir(directory):
    match = pattern.match(filename)
    if match:
        file_number = match.group(1)  
        if file_number in target_numbers:
            file_path = os.path.join(directory, filename)
            os.remove(file_path)
            deleted_files.append(filename)
            print(f"已删除: {filename}")

if deleted_files:
    print("\n删除完成，以下是已删除的文件：")
    for f in deleted_files:
        print(f)
else:
    print("\n未找到匹配文件！")
