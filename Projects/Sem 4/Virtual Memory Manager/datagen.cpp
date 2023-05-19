#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int PhysicalMemorySize = 65536;

int main() {
    srand(static_cast<unsigned>(time(0)));    
    vector<char> physical_memory(PhysicalMemorySize);
    
    for (int i = 0; i < PhysicalMemorySize; ++i) {
        physical_memory[i] = rand() % 256 - 128;  
    }

    ofstream file("physical_memory.bin", ios::binary);
    if (!file) {
        cout << "Error opening physical memory file." << endl;
        return 1;
    }
    file.write(reinterpret_cast<char*>(physical_memory.data()), PhysicalMemorySize);

    cout << "Physical memory file generated successfully." << endl;

    file.close();

    return 0;
}
