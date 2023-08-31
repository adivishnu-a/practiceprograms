//AP21110010186 - Adi Vishnu Avula

#include <stdio.h>
#include <string.h>

#define N strlen(divisor_val)

int data_length, i, j;
char data[30], divisor_val[30], crc_val[30];

void XOR() {
    for (j = 1; j < N; j++)
        crc_val[j] = (crc_val[j] == divisor_val[j]) ? '0' : '1';
}

void crc_gen() {
    for (i = 0; i < N; i++)
        crc_val[i] = data[i];
    do {
        if (crc_val[0] == '1')
            XOR();
        for (j = 0; j < N - 1; j++)
            crc_val[j] = crc_val[j + 1];
        crc_val[j] = data[i++];
    } while (i <= data_length + N - 1);
}

void receiver() {
    printf("\nEnter the received data: ");
    scanf("%s", data);
    crc_gen();
    for (i = 0; i < N - 1 && crc_val[i] != '1'; i++);
    if (i < N - 1)
        printf("\nERROR DETECTED IN TRANSMISSION");
    else
        printf("\nNO ERROR DETECTED IN TRANSMISSION");
}

int main() {
    printf("Enter data to be transmitted: ");
    scanf("%s", data);
    printf("Enter the divisor: ");
    scanf("%s", divisor_val);
    data_length = strlen(data);
    for (i = data_length; i < data_length + N - 1; i++)
        data[i] = '0';
    printf("Adjusted data with n-1 zeros: %s\n", data);
    crc_gen();
    printf("CRC is: %s\n", crc_val);
    for (i = data_length; i < data_length + N - 1; i++)
        data[i] = crc_val[i - data_length];
    printf("\nFinal data to be transmitted from sender: %s\n", data);
    receiver();
    return 0;
}
