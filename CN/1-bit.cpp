#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;


bool hasError() {
    return (rand() % 100) < 10; 
}

int main() {
    srand(time(nullptr));

    int frame = 0; 
    int ack = 0;   

    while (true) {
        
        cout << "Sender: Sending Frame " << frame << endl;
        
        if (hasError()) {
            cout << "Sender: Frame " << frame << " lost or damaged. Retransmitting..." << endl;
        } else {
            
            usleep(200000); 

            
            cout << "Receiver: Received Frame " << frame << endl;

            if (frame == ack) {
                cout << "Receiver: Acknowledging Frame " << ack << endl;
                ack++; 
            } else {
                cout << "Receiver: Discarding Frame " << frame << endl;
            }

            
            usleep(200000); 

            
            frame++;

            if (frame == 10) {
                cout << "Sender: All frames sent successfully. Exiting..." << endl;
                break;
            }
        }
    }

    return 0;
}
