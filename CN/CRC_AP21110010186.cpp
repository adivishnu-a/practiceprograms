//AP21110010186 - Adi Vishnu Avula

#include <iostream>
#include <string>
using namespace std;

int datalen;
string message, crcval, divisor, rmessage;

void XOR() {
    for (int j = 1; j < divisor.length(); j++)
        crcval[j] = (crcval[j] == divisor[j]) ? '0' : '1';
}

void crc_calc() {
    crcval = message;
    int N = divisor.length();
    for (int i = 0; i <= datalen; i++) {
        if (crcval[0] == '1')
            XOR();
        
        crcval = crcval.substr(1) + message[i];
    }
}

void receiver() {
    cout << "\nEnter the received data: ";
    cin >> rmessage;
    cout << "\nData received: " << rmessage;
    crc_calc();

    if (crcval == rmessage) {
        cout << "\nNo error detected\n\n";
    } else {
        cout << "\nError detected\n\n";
    }
}

int main() {
    cout << "\nEnter data to be transmitted: ";
    cin >> message;
    cout << "\nEnter the Divisor: ";
    cin >> divisor;
    datalen = message.length();
    
    int N = divisor.length();
    for (int i = datalen; i < datalen + N - 1; i++) {
        message.push_back('0');
    }
    
    cout << "\nData with n-1 added zeroes: " << message;
    crc_calc();
    cout << "\nCRC is: " << crcval;
    
    for (int i = datalen; i < datalen + N - 1; i++) {
        message[i] = crcval[i - datalen];
    }
    
    cout << "\nFinal data to be sent: " << message;
    receiver();
    return 0;
}
