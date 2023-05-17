import multiprocessing

# Function to be executed in parallel
def process_data(data_chunk):
    # Process the data chunk
    result = data_chunk * 2
    return result

if __name__ == '__main__':
    # Input data
    data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]

    # Number of cores to use
    num_cores = multiprocessing.cpu_count()

    # Create a pool of worker processes
    pool = multiprocessing.Pool(processes=num_cores)

    # Divide the data into chunks
    chunk_size = len(data)//num_cores 
    if(chunk_size == 0):
        chunk_size = 1
    data_chunks = [data[i:i+chunk_size] for i in range(0, len(data), chunk_size)]

    # Apply the function to each data chunk in parallel
    results = pool.map(process_data, data_chunks)

    # Close the pool of worker processes
    pool.close()
    pool.join()

    # Print the results
    print(results)
