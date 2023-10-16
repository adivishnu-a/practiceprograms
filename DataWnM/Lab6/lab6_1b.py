data = [13, 15, 16, 16, 19, 20, 20, 21, 22, 22, 25, 25, 25, 25, 30, 33, 33, 35, 35, 35, 35, 36, 40, 45, 46, 52, 70]
bin_no = 9
bin_size = len(data) // bin_no
bins = []

for i in range(bin_no):
    m = i * bin_size
    n = (i + 1) * bin_size
    if i == bin_no - 1:
        bin_data = data[m:]
    else:
        bin_data = data[m:n]
    bin_mean = sum(bin_data) / len(bin_data)  
    bins.append([round(bin_mean, 2)] * len(bin_data))  

print("Bins with Bin Means: \n")
for i, bin_data in enumerate(bins):
    bin_mean = round(sum(bin_data) / len(bin_data), 2)  
    print(f"Bin {i + 1} : [{' '.join(map(str, bin_data))}]")
