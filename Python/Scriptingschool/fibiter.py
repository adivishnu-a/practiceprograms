n=15
print("0, 1", end="")
a=0
b=1
sum=a+b
while(sum<15):
    print(", ",sum, end="")
    a=b
    b=sum
    sum=a+b