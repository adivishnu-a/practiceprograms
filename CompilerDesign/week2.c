#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct TableEntry {
    char lexis[50];
    int token;
};

struct TableEntry symbolTable[50];
int size = 0;

void addToSymbolTable(char lexis[]) {
    strcpy(symbolTable[size].lexis, lexis);
    size++;
}

int searchInSymbolTable(char lexis[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(lexis, symbolTable[i].lexis) == 0) {
            return symbolTable[i].token;
        }
    }
    return -1;
}

int keywordIdentifierToken(char lexis[]) {
    if (strcmp(lexis, "if") == 0 || strcmp(lexis, "else") == 0 || strcmp(lexis, "print") == 0 || strcmp(lexis, "for") == 0 || strcmp(lexis, "while") == 0 || strcmp(lexis, "do") == 0 || strcmp(lexis, "int") == 0 || strcmp(lexis, "float") == 0 || strcmp(lexis, "return") == 0 || strcmp(lexis, "break") == 0)
        return 1;
    
    return -1; 
}

bool isInteger(char lexis[]) {
    for (int i = 0; lexis[i] != '\0'; i++) {
        if (lexis[i] < '0' || lexis[i] > '9') {
            return false;
        }
    }
    return true;
}

bool isOperator(char lexis[]) {
    for (int i = 0; lexis[i] != '\0'; i++) {
        if (lexis[i] == '<' || lexis[i] == '>' || lexis[i] == '=' || lexis[i] == '!') {
            return true; 
        }
    }
    return false; 
}

bool isIdentifier(char lexis[]) {
    if ((lexis[0] >= 'a' && lexis[0] <= 'z') || (lexis[0] >= 'A' && lexis[0] <= 'Z')) {
        for (int i = 0; lexis[i] != '\0'; i++) {
            if (!((lexis[i] >= 'a' && lexis[i] <= 'z') || (lexis[i] >= 'A' && lexis[i] <= 'Z') || (lexis[i] >= '0' && lexis[i] <= '9'))) {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main() {
    FILE *inputFile = fopen("input.txt", "r"); 
    FILE *outputFile = fopen("output.txt", "w"); 
    
    char lexis[50];
    
    while (fscanf(inputFile, "%s", lexis) != EOF) {
        int token = keywordIdentifierToken(lexis);
        if (token == -1) {
            if (isInteger(lexis)) {
                token = 2; 
            } else {
                if (isOperator(lexis))
                    token = 3;
                else if (isIdentifier(lexis)) { 
                    token = 4;
                    if (searchInSymbolTable(lexis) == -1)
                        addToSymbolTable(lexis);
                }
            }
        }
        if (token == 1)
            fprintf(outputFile, "Type: Keyword, lexis: %s\n", lexis);
        else if (token == 2)
            fprintf(outputFile, "Type: Integer, lexis: %s\n", lexis);
        else if (token == 3)
            fprintf(outputFile, "Type: Operator, lexis: %s\n", lexis);
        else if (token == 4)
            fprintf(outputFile, "Type: Identifier, lexis: %s\n", lexis);
        else
            fprintf(outputFile, "Invalid lexis: %s\n", lexis);
    }
    
    fprintf(outputFile, "\n\n\nSymbol Table:\n");
    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "lexis: %s\n", symbolTable[i].lexis);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
