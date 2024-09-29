#include <stdio.h>
#include <ctype.h>

int isValidIdentifierStart(char ch) {
    return (ch == '_' || isalpha(ch));
}

int isValidIdentifierChar(char ch) {
    return (ch == '_' || isalnum(ch));
}

int main() {
    FILE *inputFile, *outputFile;
    char ch, nextCh;

    // Open input and output files
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: cannot open input file\n");
        return 1;
    }

    outputFile = fopen("output_scanner.txt", "w");
    if (outputFile == NULL) {
        printf("Error: cannot open output file\n");
        fclose(inputFile);
        return 1;
    }

    // Main scanning loop
    while ((ch = fgetc(inputFile)) != EOF) {
        nextCh = fgetc(inputFile); // Peek next character

        // Identifier detection
        if (isValidIdentifierStart(ch)) {
            fputc(toupper(ch), outputFile);
            while (isValidIdentifierChar(nextCh)) {
                fputc(toupper(nextCh), outputFile);
                ch = nextCh;
                nextCh = fgetc(inputFile);
            }
            fputc(' ', outputFile); // Add a space after identifier
            ungetc(nextCh, inputFile); // Return next char to stream

        // Compound operators and single operators
        } else if (ch == '+') {
            if (nextCh == '+') {
                fprintf(outputFile, "PLUS (INCREMENT) ");
            } else if (nextCh == '=') {
                fprintf(outputFile, "PLUS (ADD ASSIGN) ");
            } else {
                fprintf(outputFile, "PLUS ");
                ungetc(nextCh, inputFile); // Return next char to stream
            }
        } else if (ch == '-') {
            if (nextCh == '-') {
                fprintf(outputFile, "MINUS (DECREMENT) ");
            } else if (nextCh == '=') {
                fprintf(outputFile, "MINUS (MINUS ASSIGN) ");
            } else {
                fprintf(outputFile, "MINUS ");
                ungetc(nextCh, inputFile); // Return next char to stream
            }
        } else if (ch == '*') {
            if (nextCh == '=') {
                fprintf(outputFile, "MULTIPLY (MULTIPLY ASSIGN) ");
            } else {
                fprintf(outputFile, "MULTIPLY ");
                ungetc(nextCh, inputFile);
            }
        } else if (ch == '/') {
            fprintf(outputFile, "DIVIDE ");
        } else if (ch == '%') {
            fprintf(outputFile, "MODULO ");
        } else if (ch == '@') {
            fprintf(outputFile, "AT ");
        } else if (ch == '&') {
            fprintf(outputFile, "BITWISE AND ");
        } else if (ch == '^') {
            fprintf(outputFile, "BITWISE XOR ");
        } else if (ch == '=') {
            if (nextCh == '=') {
                fprintf(outputFile, "ASSIGN (EQUAL) ");
            } else {
                fprintf(outputFile, "ASSIGN ");
                ungetc(nextCh, inputFile);
            }
        }

        // Special characters
        else if (ch == '.') {
            fprintf(outputFile, "(DOT) ");
        } else if (ch == ',') {
            fprintf(outputFile, "(COMMA) ");
        } else if (ch == ':') {
            fprintf(outputFile, "(COLON) ");
        } else if (ch == ';') {
            fprintf(outputFile, "(SEMICOLON) ");
        } else if (ch == ' ' || ch == '\n') {
            fputc(ch, outputFile);  // Preserve spaces and newlines
        }
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Scanning complete! Output written to output_scanner.txt\n");

    return 0;
}
