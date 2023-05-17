import psutil
import time
import datetime
import matplotlib.pyplot as plt

# Configuration
monitoring_interval = 60  # Time interval between each resource check in seconds
history_file = 'resource_history.log'  # File to store historical resource data

# Initialize lists to store resource data
timestamps = []
cpu_percentages = []
memory_percentages = []
io_counters = []
network_bytes_sent = []
network_bytes_received = []

def log_resource_data(timestamp, cpu_percent, memory_percent, io_counter, network_bytes_sent, network_bytes_received):
    with open(history_file, 'a') as file:
        file.write(f'{timestamp},{cpu_percent},{memory_percent},{io_counter},{network_bytes_sent},{network_bytes_received}\n')

def plot_resource_graph():
    plt.figure(figsize=(12, 6))
    plt.title('Resource Utilization')
    plt.xlabel('Time')
    plt.ylabel('Utilization (%)')
    plt.plot(timestamps, cpu_percentages, label='CPU')
    plt.plot(timestamps, memory_percentages, label='Memory')
    plt.plot(timestamps, io_counters, label='I/O')
    plt.plot(timestamps, network_bytes_sent, label='Network Sent')
    plt.plot(timestamps, network_bytes_received, label='Network Received')
    plt.legend()
    plt.show()

def monitor_resources():
    while True:
        # Get current resource usage
        timestamp = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        cpu_percent = psutil.cpu_percent()
        memory_percent = psutil.virtual_memory().percent
        io_counter = psutil.disk_io_counters().read_count + psutil.disk_io_counters().write_count
        network_stats = psutil.net_io_counters()
        network_sent = network_stats.bytes_sent
        network_received = network_stats.bytes_recv

        # Log resource data
        log_resource_data(timestamp, cpu_percent, memory_percent, io_counter, network_sent, network_received)

        # Update lists with resource data
        timestamps.append(timestamp)
        cpu_percentages.append(cpu_percent)
        memory_percentages.append(memory_percent)
        io_counters.append(io_counter)
        network_bytes_sent.append(network_sent)
        network_bytes_received.append(network_received)

        # Wait for the monitoring interval
        time.sleep(monitoring_interval)

try:
    # Clear the resource history file
    open(history_file, 'w').close()

    # Start monitoring resources
    monitor_resources()

except KeyboardInterrupt:
    # Plot resource utilization graph when interrupted by the user
    plot_resource_graph()
