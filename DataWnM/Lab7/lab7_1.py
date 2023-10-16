data = [-10, 201, 301, -401, 501, 601, 701]

m = max(map(abs, data))

n = len(str(m))
n_data = [round(x / 10**n, 3) for x in data]

print("The initial data is:", end=" ")
for val in data:
    print(val, end=" ")
print("\nThe normalized data is:", end=" ")
for val in n_data:
    print(val, end=" ")
