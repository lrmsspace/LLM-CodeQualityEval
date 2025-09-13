import os
import xml.etree.ElementTree as ET
import csv
import pandas as pd

XML_FOLDER = r"F:\LLM-CodeQualityEval\QualityScan\CPP\Codeium"
OUTPUT_CSV = os.path.join(XML_FOLDER, "cppcheck_report.csv")
OUTPUT_XLSX = os.path.join(XML_FOLDER, "cppcheck_report.xlsx")

results = []

for filename in os.listdir(XML_FOLDER):
    if filename.endswith(".xml"):
        xml_path = os.path.join(XML_FOLDER, filename)

        parts = filename[:-4].split("-")  
        if len(parts) >= 2:
            difficulty = parts[0]
            index = parts[1]
        else:
            difficulty = "Unknown"
            index = "Unknown"

        try:
            tree = ET.parse(xml_path)
            root = tree.getroot()

            for error in root.findall(".//error"):
                msg = error.attrib.get("msg", "")
                severity = error.attrib.get("severity", "")
                error_id = error.attrib.get("id", "")

                for loc in error.findall("location"):
                    file = loc.attrib.get("file", "")
                    line = loc.attrib.get("line", "")
                    results.append([
                        index,         
                        filename,     
                        difficulty,   
                        file,         
                        line,         
                        severity,     
                        error_id,     
                        msg           
                    ])
        except Exception as e:
            print(f"⚠️ 解析失败：{filename} -> {e}")

with open(OUTPUT_CSV, "w", newline="", encoding="utf-8") as f:
    writer = csv.writer(f)
    writer.writerow(["索引", "报告文件", "问题难度", "源代码文件", "行号", "严重程度", "问题ID", "问题描述"])
    writer.writerows(results)
