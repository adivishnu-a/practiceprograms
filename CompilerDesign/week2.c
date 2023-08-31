#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct TableEntry {
    char lexeme[50];
    int token;
};

struct TableEntry symbolTable[50];
int size = 0;

void addToSymbolTable(char lexeme[]) {
    strcpy(symbolTable[size].lexeme, lexeme);
    size++;
}

int searchInSymbolTable(char lexeme[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(lexeme, symbolTable[i].lexeme) == 0) {
            return symbolTable[i].token;
        }
    }
    return -1;
}

int keywordIdentifierToken(char lexeme[]) {
    if (strcmp(lexeme, "if") == 0 || strcmp(lexeme, "else") == 0 || strcmp(lexeme, "print") == 0 || strcmp(lexeme, "for") == 0 || strcmp(lexeme, "while") == 0 || strcmp(lexeme, "do") == 0 || strcmp(lexeme, "int") == 0 || strcmp(lexeme, "float") == 0 || strcmp(lexeme, "return") == 0 || strcmp(lexeme, "break") == 0)
        return 1;
    
    return -1; 
}

bool isInteger(char lexeme[]) {
    for (int i = 0; lexeme[i] != '\0'; i++) {
        if (lexeme[i] < '0' || lexeme[i] > '9') {
            return false;
        }
    }
    return true;
}

bool isOperator(char lexeme[]) {
    for (int i = 0; lexeme[i] != '\0'; i++) {
        if (lexeme[i] == '<' || lexeme[i] == '>' || lexeme[i] == '=' || lexeme[i] == '!') {
            return true; 
        }
    }
    return false; 
}

bool isIdentifier(char lexeme[]) {
    if ((lexeme[0] >= 'a' && lexeme[0] <= 'z') || (lexeme[0] >= 'A' && lexeme[0] <= 'Z')) {
        for (int i = 0; lexeme[i] != '\0'; i++) {
            if (!((lexeme[i] >= 'a' && lexeme[i] <= 'z') || (lexeme[i] >= 'A' && lexeme[i] <= 'Z') || (lexeme[i] >= '0' && lexeme[i] <= '9'))) {
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
    
    char lexeme[50];
    
    while (fscanf(inputFile, "%s", lexeme) != EOF) {
        int token = keywordIdentifierToken(lexeme);
        if (token == -1) {
            if (isInteger(lexeme)) {
                token = 2; 
            } else {
                if (isOperator(lexeme))
                    token = 3;
                else if (isIdentifier(lexeme)) { 
                    token = 4;
                    if (searchInSymbolTable(lexeme) == -1)
                        addToSymbolTable(lexeme);
                }
            }
        }
        if (token == 1)
            fprintf(outputFile, "Type: Keyword, lexeme: %s\n", lexeme);
        else if (token == 2)
            fprintf(outputFile, "Type: Integer, lexeme: %s\n", lexeme);
        else if (token == 3)
            fprintf(outputFile, "Type: Operator, lexeme: %s\n", lexeme);
        else if (token == 4)
            fprintf(outputFile, "Type: Identifier, lexeme: %s\n", lexeme);
        else
            fprintf(outputFile, "Invalid lexeme: %s\n", lexeme);
    }
    
    fprintf(outputFile, "\n\n\nSymbol Table:\n");
    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "lexeme: %s\n", symbolTable[i].lexeme);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
