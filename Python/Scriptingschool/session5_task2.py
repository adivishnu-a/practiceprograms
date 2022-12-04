#Accept a Number, and check whether the given number is three-digit number or not
num = int(input("Enter a number : "))
if num>99 and num<1000:
    print("The number is three-digit number")
else:
    print("The number is not a three-digit number")