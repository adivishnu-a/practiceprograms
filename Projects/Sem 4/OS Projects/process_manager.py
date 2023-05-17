import psutil

def identify_processes():
    # Get a list of all running processes
    all_processes = psutil.process_iter()

    # Define CPU and I/O thresholds to differentiate between CPU-bound and I/O-bound processes
    cpu_threshold = 50  # Percentage of CPU utilization to consider a process as CPU-bound
    io_threshold = 50   # Percentage of I/O utilization to consider a process as I/O-bound

    for process in all_processes:
        try:
            # Get process information
            process_info = process.as_dict(attrs=['pid', 'name', 'cpu_percent', 'memory_percent', 'io_counters'])

            # Identify the process type based on CPU and I/O utilization
            if process_info['cpu_percent'] > cpu_threshold:
                process_info['type'] = 'CPU-bound'
            elif process_info['io_counters'] and process_info['io_counters'].read_bytes > io_threshold:
                process_info['type'] = 'I/O-bound'
            else:
                process_info['type'] = 'Unknown'

            # Print process information
            print(f"PID: {process_info['pid']}")
            print(f"Name: {process_info['name']}")
            print(f"CPU Percent: {process_info['cpu_percent']}")
            print(f"Memory Percent: {process_info['memory_percent']}")
            print(f"I/O Utilization: {process_info['io_counters']}")
            print(f"Process Type: {process_info['type']}")
            print("------------------------")

        except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
            # Handle exceptions if a process is terminated or inaccessible
            pass

# Call the function to identify processes
identify_processes()
