#include<stdio.h>
#define max 100

int main() {
    char str[max], f = 'a';
    int i;

    FILE *infile = fopen("input.txt", "r");
    if (infile == NULL) {
        printf("Input file not found\n");
        return 1;
    }
    FILE *outfile = fopen("output.txt", "w");

    fscanf(infile, "%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        switch (f) {
            case 'a':
                if (str[i] == '0')
                    f = 'b';
                else if (str[i] == '1')
                    f = 'a';
                break;
            case 'b':
                if (str[i] == '0')
                    f = 'b';
                else if (str[i] == '1')
                    f = 'c';
                break;
            case 'c':
                if (str[i] == '0')
                    f = 'b';
                else if (str[i] == '1')
                    f = 'a';
                break;
        }
    }

    if (f == 'c')
        fprintf(outfile, "String is accepted\n");
    else
        fprintf(outfile, "String is not accepted\n");

    fclose(infile);
    fclose(outfile);

    printf("Processing completed\n");

    return 0;
}
