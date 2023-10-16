#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEYWORD 1
#define IDENTIFIER 2
#define CONSTANT 3
#define OPERATOR 4
#define DELIMITER 5

int isKeyword(char* token) {
    char* keywords[] = {"int", "if", "then", "else", "endif", "while", "do", "enddo", "print"};
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *fp = fopen("C:\\Users\\adivi\\Documents\\GitHub\\practiceprograms\\CompilerDesign\\program.txt", "r");
    if (fp == NULL) {
        printf("File Not Found\n");
        return 1;
    }

    char currchar;
    char token[100];
    int tindex = 0;
    int ttype;

    while ((currchar = fgetc(fp)) != EOF) {
        if (isspace(currchar)) {
            continue;
        } else if (currchar == '/') {
            if ((currchar = fgetc(fp)) == '*') {
                while ((currchar = fgetc(fp)) != EOF) {
                    if (currchar == '*') {
                        if ((currchar = fgetc(fp)) == '/') {
                            break;
                        }
                    }
                }
            } else {
                ungetc(currchar, fp);
            }
        }

        if (isalpha(currchar)) {
            ttype = IDENTIFIER;
            token[tindex++] = currchar;
            while ((currchar = fgetc(fp)) != EOF && isalnum(currchar)) {
                token[tindex++] = currchar;
            }
            ungetc(currchar, fp);
        } else if (isdigit(currchar)) {
            ttype = CONSTANT;
            token[tindex++] = currchar;
            while ((currchar = fgetc(fp)) != EOF && isdigit(currchar)) {
                token[tindex++] = currchar;
            }
            ungetc(currchar, fp);
        } else if (strchr("=<>&!+-*/{}[]();", currchar) != NULL) {
            ttype = OPERATOR;
            token[tindex++] = currchar;
        } else {
            ttype = -1;
        }

        if (ttype != -1) {
            token[tindex] = '\0';
            if (isKeyword(token)) {
                printf("Keyword: %s\n", token);
            } else {
                switch (ttype) {
                    case IDENTIFIER:
                        printf("Identifier: %s\n", token);
                        break;
                    case CONSTANT:
                        printf("Constant: %s\n", token);
                        break;
                    case OPERATOR:
                        printf("Operator: %s\n", token);
                        break;
                    case DELIMITER:
                        printf("Delimiter: %s\n", token);
                        break;
                }
            }

            tindex = 0;
        }
    }

    fclose(fp);
    return 0;
}
