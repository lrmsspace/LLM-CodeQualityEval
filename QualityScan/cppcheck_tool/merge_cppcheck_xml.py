import os
import glob
import xml.etree.ElementTree as ET

input_dir = r'F:\check_tongyi\cppcheck_results'
output_file = os.path.join(input_dir, 'cppcheck-all.xml')

root = ET.Element('results', {'version': '2'})
ET.SubElement(root, 'cppcheck', {'version': '2.x'})  
errors_elem = ET.SubElement(root, 'errors')

for file_path in glob.glob(os.path.join(input_dir, '*.xml')):
    if os.path.basename(file_path) == 'cppcheck-all.xml':
        continue  

    try:
        tree = ET.parse(file_path)
        file_root = tree.getroot()
        file_errors = file_root.find('errors')
        if file_errors is not None:
            for error in file_errors:
                errors_elem.append(error)
        print(f'✅ 合并: {os.path.basename(file_path)}')
    except ET.ParseError as e:
        print(f'❌ 解析失败: {file_path}, 错误: {e}')

tree = ET.ElementTree(root)
tree.write(output_file, encoding='utf-8', xml_declaration=True)

