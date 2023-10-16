//AP21110010186 - Adi Vishnu Avula

#include<iostream>
using namespace std;

int calc_hamming(int *data, int *red, int dsize, int rbits) {
    int hcode[dsize + rbits] = {0};
    int count = 0, k = 0, r = rbits;

    for (int i = dsize + rbits; i > 0; i--) {
        if (r > 0 && red[r - 1] == i) {
            hcode[i] = 0;
            r--;
        } else {
            hcode[i] = data[k++];
        }
    }
    
    for (int i = 0; i < rbits; i++) {
        for (int j = 1; j <= dsize + rbits; j++) {
            if ((1 << i) & j) {
                if (hcode[j] == 1) {
                    count++;
                }
            }
        }
        hcode[red[i]] = (count % 2 == 0) ? 0 : 1;
        count = 0;
    }
    cout << "\nHamming Code:";
    for (int i = dsize + rbits; i > 0; i--) {
        cout << hcode[i];
    }
    cout<<endl;
    return 0;
}

int main() {
    int dsize, a = 2, rbits = 1;
    cout << "Enter the number of bits: ";
    cin >> dsize;

    while (1) {
        if (a >= (dsize + 1 + rbits)) {
            break;
        }
        rbits++;
        a *= 2;
    }
    int data[dsize];
    int red[5] = {1, 2, 4, 8, 16};
    cout<<"Enter data bits one by one starting from LSB:"<<endl;
    for (int i = 0; i < dsize; i++) {
        cout << "Input data bit: ";
        cin >> data[i];
    }
    if (data[0] == 0) {
        cout << "Invalid Input";
        exit(0);
    }
    calc_hamming(data, red, dsize, rbits);
    return 0;
}
