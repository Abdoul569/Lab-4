#include<stdio.h>
#include<ctype.h>

// Function to check if a character is the start of an identifier (letter or underscore)
int isValidIdentifierStart(char ch) {
    return (ch == '_' || isalpha(ch));
}

// Function to check if a character can be part of an identifier (letter, number, or underscore)
int isValidIdentifierChar(char ch) {
    return (ch == '_' || isalnum(ch));
}

int main() {
    FILE *inputFile, *outputFile;
    char ch, nextCh;

    
    inputFile = fopen("input.txt", "r"); // Open the input file in read mode
    if (inputFile == NULL) {
        printf("Error: cannot open input file\n");
        return 1;
    }

   
    outputFile = fopen("output_scanner.txt", "w");  // Open the output file in writing mode
    if (outputFile == NULL) {
        printf("Error: cannot open output file\n");
        fclose(inputFile);  // Close input file if output file can't open
        return 1;
    }

    // Read the input file one character at a time
    while ((ch = fgetc(inputFile)) != EOF) {
        nextCh = fgetc(inputFile); // Peek at the next character

        // Handle identifiers (words or variable names)
        if (isValidIdentifierStart(ch)) {
            fputc(toupper(ch), outputFile);
            while (isValidIdentifierChar(nextCh)) {
                fputc(toupper(nextCh), outputFile);
                ch = nextCh;
                nextCh = fgetc(inputFile);
            }
            fputc(' ', outputFile);  // Add a space after identifiers
            ungetc(nextCh, inputFile); // Return the next character to the stream

        // Handle compound and basic operators
        } else if (ch == '+') {
            if (nextCh == '+') {
                fprintf(outputFile, "PLUS (INCREMENT) ");
            } else if (nextCh == '=') {
                fprintf(outputFile, "PLUS (ADD ASSIGN) ");
            } else {
                fprintf(outputFile, "PLUS ");
                ungetc(nextCh, inputFile);  // Return the next character
            }
        } else if (ch == '-') {
            if (nextCh == '-') {
                fprintf(outputFile, "MINUS (DECREMENT) ");
            } else if (nextCh == '=') {
                fprintf(outputFile, "MINUS (MINUS ASSIGN) ");
            } else {
                fprintf(outputFile, "MINUS ");
                ungetc(nextCh, inputFile); // Return the next character
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
                ungetc(nextCh, inputFile); // Return the next character
            }
        }

        // Handle special characters (.,:,;,)
        else if (ch == '.') {
            fprintf(outputFile, "(DOT) ");
        } else if (ch == ',') {
            fprintf(outputFile, "(COMMA) ");
        } else if (ch == ':') {
            fprintf(outputFile, "(COLON) ");
        } else if (ch == ';') {
            fprintf(outputFile, "(SEMICOLON) ");
        }

        // Preserve spaces and newlines
        else if (ch == ' ' || ch == '\n') {
            fputc(ch, outputFile);
        }
    }

    // Close both input and output files
    fclose(inputFile);
    fclose(outputFile);
    
    printf("Special characters recognized and written to output_scanner.txt successfully!\n");
    
    return 0;
}
