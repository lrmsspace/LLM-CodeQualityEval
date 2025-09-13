import pandas as pd

file_path = 'code_smell_Python.xlsx'  
language = 'Python' 

xls = pd.ExcelFile(file_path)
summary = []

for sheet_name in xls.sheet_names:
    df = pd.read_excel(xls, sheet_name=sheet_name)

    rule_counts = df['Rule'].value_counts()
    rule_percent = df['Rule'].value_counts(normalize=True) * 100
    rule_percent = rule_percent.round(6)
    total = rule_counts.sum()

    row = {
        'Language': language,
        'Model': sheet_name,
        'Sum': total
    }
    for rule in rule_counts.index:
        row[rule] = rule_counts[rule]
        row[f"{rule} (%)"] = round(rule_percent[rule], 4)

    summary.append(row)

summary_df = pd.DataFrame(summary)

summary_df = summary_df.fillna(0)
output_file = 'code_smell_frequency_Python.xlsx'
summary_df.to_excel(output_file, index=False)

