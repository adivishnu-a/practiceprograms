#Session 5 - Task 1
num1 = int(input("Enter num1 : "))
num2 = int(input("Enter num2 : "))
print("Chose the operation:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Power of\n6. Mode")
ch = int(input("Enter Choice : "))
if ch==1:
    print("num1 + num2 = ",(num1+num2))
elif ch==2:
    print("num1 - num2 = ",(num1-num2))
elif ch==3:
    print("num1 * num2 = ",(num1*num2))
elif ch==4:
    print("num1 / num2 = ",(num1/num2))
elif ch==5:
    print("num1 ^ num2 = ",(num1**num2))
elif ch==6:
    print("num1 % num2 = ",(num1%num2))
else:
    print("Wrong Option")