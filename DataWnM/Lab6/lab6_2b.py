data = [13, 15, 16, 16, 19, 20, 20, 21, 22, 22, 25, 25, 25, 25, 30, 33, 33, 35, 35, 35, 35, 36, 40, 45, 46, 52, 70]

min_val = min(data)
max_val = max(data)

normalized_data = [round((x - min_val) / (max_val - min_val) * (1 - 0) + 0, 2) for x in data]

print("Original Data\tNormalized Data:")
for original, normalized in zip(data, normalized_data):
    print(f"{original}\t\t{normalized:.2f}")
