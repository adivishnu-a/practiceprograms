data = [200, 300, 400, 600, 1000]

mean = sum(data) / len(data)

std_dev = (sum((x - mean) ** 2 for x in data) / len(data)) ** 0.5

z_scores = [round(((x - mean) / std_dev),3) for x in data]

print("Data Before Z-Score Normalization:", end=" ")
for val in data:
    print(val, end=" ")
print("\nData After Z-Score Normalization:", end=" ")
for val in z_scores:
    print(val, end=" ")