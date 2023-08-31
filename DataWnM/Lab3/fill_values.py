import pandas as pd
import numpy as np
data = {
    "EmpName": ["T. Ramesh", "M. Soumya", "R. Shyam", "S. Raghu"],
    "EmpId": ['20001', '20002', '20003', np.nan],
    "EmpDesig": ["Asst. Prof.", "Asst. Prof.", np.nan, "Asst. Prof."],
    "EmpSalary": [150000, 120000, 140000, np.nan]
}
df = pd.DataFrame(data)

df["EmpSalary"].replace(np.nan,df["EmpSalary"].mean(),inplace=True)
df.replace(np.nan,"NA",inplace=True)

with open("Employee.txt","w") as f:
    f.write(str(df))