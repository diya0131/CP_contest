import os
import subprocess

path = "words"
exe_path = "a.exe"

for file in os.listdir(path):
    strs = file.split(".")
    if strs[1]=="in":
        input_path = os.path.join(path, file)
        with open(input_path, 'r') as file:
            input_data = file.read()
        out_path = os.path.join( path, strs[0]+".out."+strs[2])
      
        with open(out_path, 'r') as file:
            expected_output = file.read().strip()
        # output= "12"
        result = subprocess.run([exe_path], input=input_data, capture_output=True, text=True, check=True)
        
        output = result.stdout.strip()

        if output == expected_output:
            print(f"done {strs[2]}")
        else:
            print(f"error {strs[2]}\n output: {output}\n expected: {expected_output}")
# print("hello")