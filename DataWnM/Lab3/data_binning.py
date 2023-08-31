def ef_bin(data, bin_nos):
    datasorted = sorted(data)
    bin_size = len(data) // bin_nos
    bins = []
    for i in range(0, len(datasorted), bin_size):
        bin_data = datasorted[i:i+bin_size]
        bins.append(bin_data)
    return bins

def smooth_bin(bins):
    smoothed_bins = []
    for bin_data in bins:
        bin_mean = sum(bin_data) / len(bin_data)
        smoothed_bin = [bin_mean] * len(bin_data)
        smoothed_bins.append(smoothed_bin)
    return smoothed_bins

pro_nos = int(input("Enter the number of products: "))
prices = list(map(int, input("Enter the price of the products:\n").split()))
bin_nos = int(input("Enter the number of bins: "))
bins = ef_bin(prices, bin_nos)
smoothed_bins = smooth_bin(bins)
print("\nEqual frequency binning Output: \n")
for i, eq_bin in enumerate(bins, start=1):
    print(f"Bin {i}: {' '.join(map('{:.2f}'.format, eq_bin))}")
print("\nBin mean Output: \n")
for i, smoothed_bin in enumerate(smoothed_bins, start=1):
    print(f"Bin {i}: {' '.join(map('{:.2f}'.format, smoothed_bin))}")