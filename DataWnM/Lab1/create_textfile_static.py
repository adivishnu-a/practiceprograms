file=open("transactions.txt", 'w')
file.write("T1-A B C D\nT2-B C D\nT3-A B C\nT4-B C E\nT5-A C D")
file.close()
print('Success')