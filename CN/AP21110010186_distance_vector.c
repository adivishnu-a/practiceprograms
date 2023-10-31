//AP21110010186 - Adi Vishnu Avula

#include <stdio.h>
#include <limits.h>

void print_rt(char node, int rt[3][3]) {
    printf("Routing table for Node %c:\n", node);
    for (int dst = 0; dst < 3; dst++) {
        printf("Destination: %c, Cost: %d\n", 'A' + dst, rt[node - 'A'][dst]);
    }
}

void dvr(int network[3][3], int max_iter) {
    for (int iter = 0; iter < max_iter; iter++) {
        int updated_net[3][3];
        for (int node = 0; node < 3; node++) {
            for (int dst = 0; dst < 3; dst++) {
                if (node == dst) {
                    updated_net[node][dst] = 0; // Distance to itself is 0
                } else {
                    int min_cost = 99999;
                    for (int adj = 0; adj < 3; adj++) {
                        int cost = network[node][adj] + network[adj][dst];
                        if (cost < min_cost) {
                            min_cost = cost;
                        }
                    }
                    updated_net[node][dst] = min_cost;
                }
            }
        }
        for (int node = 0; node < 3; node++) {
            for (int dst = 0; dst < 3; dst++) {
                network[node][dst] = updated_net[node][dst];
            }
        }
    }

    for (int node = 0; node < 3; node++) {
        print_rt('A' + node, network);
        printf("\n");
    }
}

int main() {
    int network[3][3] = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    int max_iter = 10;
    dvr(network, max_iter);

    return 0;
}
