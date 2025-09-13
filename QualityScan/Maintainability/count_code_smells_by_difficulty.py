import pandas as pd

input_path = 'code_smell_Python.xlsx'
output_path = 'code_smell_with_difficulty_Python.xlsx'

xls = pd.ExcelFile(input_path)
sheet_names = xls.sheet_names
all_records = []
summary_counts = []

def extract_difficulty(component):
    if isinstance(component, str):
        if 'Easy/' in component:
            return 'Easy'
        elif 'Medium/' in component:
            return 'Medium'
        elif 'Hard/' in component:
            return 'Hard'
    return 'Unknown'

for sheet in sheet_names:
    df = pd.read_excel(input_path, sheet_name=sheet)
    df['Difficulty'] = df['Component'].apply(extract_difficulty)
    df['Tool'] = sheet

    df_filtered = df[['Tool', 'Difficulty', 'Rule', 'Type', 'Severity',
                      'Component', 'Message', 'Line', 'Effort']]

    all_records.append(df_filtered)

    counts = df_filtered['Difficulty'].value_counts().to_dict()
    summary_counts.append({'Tool': sheet,
                           'Easy': counts.get('Easy', 0),
                           'Medium': counts.get('Medium', 0),
                           'Hard': counts.get('Hard', 0)})

final_df = pd.concat(all_records, ignore_index=True)
final_df.to_excel(output_path, index=False)

for entry in summary_counts:
    print(f"{entry['Tool']:15} | Easy: {entry['Easy']:4} | Medium: {entry['Medium']:4} | Hard: {entry['Hard']:4}")
