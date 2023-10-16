//AP21110010186 - Adi Vishnu Avula

#include <iostream>
using namespace std;

int frameNumber = 0;
int acknowledgment = 0;

void sendFrame(int frameNum) {
    cout << "Sending Frame " << frameNum << endl;
    cout << "Frame Sent: " << frameNum << endl;
    cout << endl;
}

void receiveFrame() {
    cout << endl;
    cout << "Received Frame " << frameNumber << endl;
    if (acknowledgment == 1) {
        cout << "Frame Received and Acknowledged" << endl;
    } else {
        cout << "Frame Rejected" << endl;
    }
    cout << endl;
}

int main() {
    cout << "Enter the number of frames to be transmitted: ";
    int numFrames;
    cin >> numFrames;

    while (frameNumber < numFrames) {
        sendFrame(frameNumber);
        cout << "Enter 0 to Reject or 1 to Acknowledge: ";
        cin >> acknowledgment;
        receiveFrame();
        frameNumber++;
    }

    if (frameNumber == numFrames) {
        cout << "\nAll frames received successfully\n" << endl;
    } else {
        cout << "\nAll frames not received successfully" << endl;
    }

    return 0;
}
