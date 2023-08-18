file=open("transactions2.txt", 'w')
for i in range(5):
    t_id = input("Enter Transaction ID: ")
    num = int(input("Enter number of items purchased in the transaction: "))
    items = ""
    for j in range(num):
        item = input("Enter the item: ")
        items += item + " "
    file.write(t_id+"-"+items+"\n")
file.close()
print('Success')