import sys

# Constants
PAGE_SIZE = 256             # Size of each page in bytes
PAGE_TABLE_SIZE = 256       # Number of entries in the page table
TLB_SIZE = 16               # Number of entries in the TLB
MEMORY_SIZE = 65536         # Total size of the memory in bytes
FRAME_SIZE = 256            # Size of each frame in bytes
NUM_FRAMES = MEMORY_SIZE // FRAME_SIZE  # Number of frames in physical memory

# Initialize data structures
page_table = [-1] * PAGE_TABLE_SIZE
tlb = [[-1, -1]] * TLB_SIZE
physical_memory = [0] * MEMORY_SIZE

# Read logical addresses from file
with open('input.txt', 'r') as file:
    logical_addresses = [int(address) for address in file.read().split()]

# Function to read a page from disk and store it in physical memory
def read_page_from_disk(page_number):
    # Simulating reading the page from disk
    # In this example, we'll populate the page with consecutive values starting from page_number
    start_address = page_number * PAGE_SIZE
    end_address = start_address + PAGE_SIZE

    for i in range(start_address, end_address):
        physical_memory[i] = i - start_address

# Function to simulate the translation of logical to physical addresses
def translate_logical_to_physical(logical_address):
    # Extract page number and offset from the logical address
    page_number = (logical_address >> 8) & 0xFF
    offset = logical_address & 0xFF

    # Check if the page number is present in the TLB
    for entry in tlb:
        if entry[0] == page_number:
            frame_number = entry[1]

            # Translate the logical address to physical address
            physical_address = (frame_number << 8) | offset
            value = physical_memory[physical_address]

            return value

    # TLB miss, check if the page number is present in the page table
    if page_table[page_number] != -1:
        frame_number = page_table[page_number]

        # Translate the logical address to physical address
        physical_address = (frame_number << 8) | offset
        value = physical_memory[physical_address]

        # Update TLB with the new entry
        tlb.pop(0)
        tlb.append([page_number, frame_number])

        return value

    # Page fault, the page number is not present in both TLB and page table
    # Read the corresponding page from disk into physical memory and update TLB and page table
    frame_number = page_number % NUM_FRAMES

    # Read the page from disk
    read_page_from_disk(page_number)

    # Update page table with the new entry
    page_table[page_number] = frame_number

    # Translate the logical address to physical address
    physical_address = (frame_number << 8) | offset
    value = physical_memory[physical_address]

    # Update TLB with the new entry
    tlb.pop(0)
    tlb.append([page_number, frame_number])

    return value

# Translate each logical address to its corresponding physical address
for logical_address in logical_addresses:
    physical_value = translate_logical_to_physical(logical_address)
    print("Logical address:", logical_address)
    print("Physical address:", physical_value)
