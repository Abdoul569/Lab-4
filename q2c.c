#include<stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char ch;

    // Open the input file in read mode
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: cannot open input file\n");
        return 1;
    }

    // Open the output file in write mode
    outputFile = fopen("output_operators.txt", "w");
    if (outputFile == NULL) {
        printf("Error: cannot open output file\n");
        fclose(inputFile); // Close input file before returning
        return 1;
    }

    printf("Reading input file and writing operators to output...\n");

    // Read each character from the input file
    while ((ch = fgetc(inputFile)) != EOF) {
        printf("Read character: %c\n", ch); // Debugging output

        if (ch == '+') {
            fprintf(outputFile, "PLUS ");
        } else if (ch == '-') {
            fprintf(outputFile, "MINUS ");
        } else if (ch == '*') {
            fprintf(outputFile, "MULTIPLY ");
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
        }
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("Operators extracted and written to output_operators.txt successfully.\n");

    return 0;
}
