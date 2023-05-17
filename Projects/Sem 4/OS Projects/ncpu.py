from collections import deque

class Process:
    def __init__(self, name, burst_time):
        self.name = name
        self.burst_time = burst_time

class CPU:
    def __init__(self):
        self.current_process = None

    def assign_process(self, process):
        self.current_process = process

    def execute(self):
        if self.current_process is not None:
            print(f"Executing process {self.current_process.name}")
            self.current_process.burst_time -= 1
            if self.current_process.burst_time == 0:
                print(f"Process {self.current_process.name} completed")
                self.current_process = None


def round_robin_scheduling(processes, num_cpus, time_quantum):
    cpu_queue = deque()
    for _ in range(num_cpus):
        cpu_queue.append(CPU())

    process_queue = deque(processes)
    while process_queue:
        cpu = cpu_queue.popleft()
        process = process_queue.popleft()
        cpu.assign_process(process)

        for _ in range(time_quantum):
            for cpu in cpu_queue:
                cpu.execute()
            cpu.execute()

            if process.burst_time == 0:
                break

        if process.burst_time > 0:
            process_queue.append(process)
        cpu_queue.append(cpu)


def main():
    num_cpus = int(input("Enter the number of CPUs: "))
    time_quantum = int(input("Enter the time quantum for each CPU: "))
    num_processes = int(input("Enter the number of processes: "))

    processes = []
    for i in range(num_processes):
        name = input(f"Enter the name of process {i+1}: ")
        burst_time = int(input(f"Enter the burst time of process {i+1}: "))
        processes.append(Process(name, burst_time))

    round_robin_scheduling(processes, num_cpus, time_quantum)


if __name__ == '__main__':
    main()
