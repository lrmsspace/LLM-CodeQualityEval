import re   
import time
import os   
import pyautogui
pyautogui.FAILSAFE = True


#适用于c/c++/java
def get_empty_cpp_function_line(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    for i in range(len(lines)):
        if '(' in lines[i] and '{' in lines[i]:
            j = i + 1
            while j < len(lines) and lines[j].strip() == "":
                j += 1
            if j < len(lines) and lines[j].strip() == "}":
                return j  
    return None
    


#适用于js
def get_empty_js_function_line(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    for i in range(len(lines)):
        line = lines[i].strip()
        if re.match(r'(var|let|const)\s+\w+\s*=\s*function\s*\(.*\)\s*\{', line):
            j = i + 1
            while j < len(lines) and lines[j].strip() == "":
                j += 1
            if j < len(lines) and lines[j].strip() == "};":
                return j  
    return None


#适用于python
def get_empty_py_function_line(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    in_docstring = False
    doc_end_line = None

    for i, line in enumerate(lines):    
        if '"""' in line:
            if not in_docstring:
                in_docstring = True
            else:
                in_docstring = False
                doc_end_line = i
                break

    if doc_end_line is not None and doc_end_line + 1 < len(lines):
        return doc_end_line + 1  
    else:
        print(f"未识别 docstring 尾部: {file_path}")
        return None






def jump_to_line(line_num):
    pyautogui.hotkey('ctrl', 'g')
    time.sleep(0.5)
    pyautogui.write(str(line_num))
    pyautogui.press('enter')
    time.sleep(0.5)

def process_file_at_empty_func(file_path, target_line):
    os.system(f'code "{file_path}"')
    time.sleep(3)

    jump_to_line(target_line)  # VS Code 从 1 开始
    time.sleep(1) 

    pyautogui.hotkey('alt', 'i')  # 选中行    
    #time.sleep(0.5)
    #pyautogui.press('enter')       # 触发补全
    time.sleep(10)  
    pyautogui.hotkey('tab')   # 接受建议
    time.sleep(1)

    pyautogui.hotkey('ctrl', 's')  # 保存
    time.sleep(1)
    pyautogui.hotkey('ctrl', 'w')  # 关闭
    time.sleep(1)   

def process_cpp_folder(folder_path):
    for filename in os.listdir(folder_path):    
        if filename.endswith(".py"):
            file_path = os.path.join(folder_path, filename)
            target_line = get_empty_py_function_line(file_path) 

            if target_line is not None:
                process_file_at_empty_func(file_path, target_line + 1)
            else:
                print(f"⚠️ 跳过：未找到目标插入行 → {file_path}")

           

# 修改为你的文件夹路径  
folder_path = r"F:\Benchmark\auto_test" 
process_cpp_folder(folder_path)

            