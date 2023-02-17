def fibonacci(n, a=0, b=1):
    sum = a+b
    if sum<n:
        print(", ", sum, end="")
        fibonacci(b, sum, n)
    else:
        return

n=int(input())
print("0, 1", end="")
fibonacci(n,1,2)