# coding=utf-8
import random
import re
import requests
from lxml import etree
import openpyxl
from bs4 import BeautifulSoup
import time
from DrissionPage import ChromiumPage, WebPage, ChromiumOptions
import pandas as pd
import os


def creator(filePath):
    raw_data = pd.read_excel(filePath, header=0)
    data = raw_data.values
    for i in range(len(data)):
        extract(data[i])


def extract(data):
    index = data[0]
    url = data[1]
    difficulty = data[2]
    desc = data[3]
    c_func = str(data[4])
    cpp_func = str(data[5])
    java_func = str(data[6])
    js_func = str(data[7])
    py_func = str(data[8])
    prefix = "https://leetcode.com/problems/"
    fileName = str(index) + '-' + url[len(prefix):len(url) - 1]

    path_dict = {".c": "output/c/" + difficulty + "/", ".cpp":"output/cpp/" + difficulty + "/",".java": "output/java/" + difficulty + "/",
                 ".js": "output/javascript/" + difficulty + "/", ".py": "output/python/" + difficulty + "/"}
    content_dict = {".c": c_func,".cpp": cpp_func, ".java": java_func, ".js": js_func, ".py": py_func}
    for key, value in content_dict.items():
        filepath = path_dict[key] + fileName + key
        if not os.path.exists(path_dict[key]):
            os.makedirs(path_dict[key])
        with open(filepath, 'w', encoding="utf-8") as f:
            if key == ".py":
                f.write("#" + url + "\n")
                for comment in desc.splitlines():
                    if comment != "":
                        comment_string = "#" + comment + "\n"
                        f.write(comment_string)
            else:
                f.write("/**" + url + " */" + "\n")
                for comment in desc.splitlines():
                    if comment != "":
                        comment_string = "//" + comment + "\n"
                        f.write(comment_string)
            f.write(value)
    print(str(index) + " " + url + "    done")


def main():
    creator(r"F:\Benchmark\GitMaterial_all\ProblemInfoCrawler\AllData.xlsx")


main()

