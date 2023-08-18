c=input("Enter 1 to read transactions.txt, 2 to read transactions2.txt: ")
name="transactions.txt" if c=="1" else "transactions2.txt"
try:
    file=open(name, 'r')
    contents = file.read()
    print(contents)
    file.close()
except:
    print("An error occurred")