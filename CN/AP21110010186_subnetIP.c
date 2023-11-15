//AP21110010186 - Adi Vishnu Avula

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_ip_class(char* ip_address) {
    char* token;
    char* first_octet_str = strtok(ip_address, ".");
    int first_octet = atoi(first_octet_str);

    if (first_octet >= 1 && first_octet <= 126) {
        return "Class A";
    } else if (first_octet >= 128 && first_octet <= 191) {
        return "Class B";
    } else if (first_octet >= 192 && first_octet <= 223) {
        return "Class C";
    } else if (first_octet >= 224 && first_octet <= 239) {
        return "Class D";
    } else if (first_octet >= 240 && first_octet <= 255) {
        return "Class E";
    } else {
        return "Invalid IP Address";
    }
}

void generate_subnet(char* ip_address, int subnet_bits, char* subnet_ip) {
    char* token;
    char octets[4][4];
    int subnet_mask[4] = {0, 0, 0, 0};

    token = strtok(ip_address, ".");
    for (int i = 0; i < 4; i++) {
        strcpy(octets[i], token);
        token = strtok(NULL, ".");
    }
    for (int i = 0; i < subnet_bits; i++) {
        subnet_mask[i / 8] += 1 << (7 - (i % 8));
    }
    for (int i = 0; i < 4; i++) {
        int octet = atoi(octets[i]) & subnet_mask[i];
        sprintf(subnet_ip, "%s%d", subnet_ip, octet);
        if (i < 3) {
            sprintf(subnet_ip, "%s.", subnet_ip);
        }
    }
}

int main() {
    char ip_address[16];
    char subnet_ip[16];
    int subnet_bits;

    printf("Enter the IP address: ");
    scanf("%s", ip_address);
    
    printf("Enter the number of subnet bits: ");
    scanf("%d", &subnet_bits);
    
    char* ip_class = get_ip_class(ip_address);
    printf("IP Address Class: %s\n", ip_class);
    
    generate_subnet(ip_address, subnet_bits, subnet_ip);
    printf("Subnet IP Address: %s\n", subnet_ip);
    return 0;
}
