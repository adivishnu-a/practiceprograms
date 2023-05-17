import multiprocessing

# Function to be executed in parallel
def process_task(task_id):
    # Process the task
    result = task_id * 2
    return result

if __name__ == '__main__':
    # Number of tasks
    num_tasks = 20000000

    # Number of cores to use
    num_cores = multiprocessing.cpu_count()

    # Create a pool of worker processes
    pool = multiprocessing.Pool(processes=num_cores)

    # Apply the function to each task in parallel
    results = pool.map(process_task, range(num_tasks))

    # Close the pool of worker processes
    pool.close()
    pool.join()

    # Print the results
    print(results)
