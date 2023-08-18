#include <stdio.h>
#include <stdbool.h>
#define max 100

int main() {
    FILE *infile, *outfile;
    char str[max];
    char f = 'a';

    infile = fopen("input.txt", "r");
    if (infile == NULL) {
        printf("Input file not found\n");
        return 1;
    }

    outfile = fopen("output.txt", "w");

    while (fscanf(infile, "%s", str) != EOF) {        
        for (int i = 0; str[i] != '\0'; i++) {
            switch (f) {
                case 'a':
                    if (str[i] == '0')
                        f = 'b';
                    else if (str[i] == '1')
                        f = 'a';
                    break;
                case 'b':
                    if (str[i] == '0')
                        f = 'a';
                    else if (str[i] == '1')
                        f = 'b';
                    break;
            }
        }

        if (f == 'a')
            fprintf(outfile, "String is accepted\n");
        else
            fprintf(outfile, "String is not accepted\n");
    }

    fclose(infile);
    fclose(outfile);

    printf("Processing completed\n");

    return 0;
}
