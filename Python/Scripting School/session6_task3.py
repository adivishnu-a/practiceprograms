while True:
    num = int(input("Enter a number : "))
    if num>0:
        print("Square of number : ", (num**2))
    elif num<0:
        continue
    else:
        break