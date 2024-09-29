#include<stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char ch, nextch;

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
    while((ch = fgetc(inputFile))!= EOF) {
        nextch = fgetc(inputFile);
        if(ch == '+'){
            if(nextch == '+'){
                fprintf(outputFile, "PLUS (INCREMENT)");
            }else if(nextch == '='){
                fprintf(outputFile, "PLUS (ADD ASSIGN)");
            }else{
                fprintf(outputFile, "PLUS");
                ungetc(nextch, inputFile);
            }
        }else if(ch == '-'){
            if(nextch == '-'){
                fprintf(outputFile, "MINUS (DECREMENT)");
            }else if(nextch == '='){
                fprintf(outputFile, "MINUS (MINUS ASSIGN)");
            }else{
                fprintf(outputFile, "MINUS");
                ungetc(nextch, inputFile);
            }
        }else if (ch == '*') {
            if (nextch == '=') {
                fprintf(outputFile, "MULTIPLY (MULTIPLY ASSIGN) ");
            } else {
                fprintf(outputFile, "MULTIPLY ");
                ungetc(nextch, inputFile);
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
            if (nextch == '=') {
                fprintf(outputFile, "ASSIGN (EQUAL) ");
            } else {
                fprintf(outputFile, "ASSIGN ");
                ungetc(nextch, inputFile);  // Put back the next character
            }
        }
    }
// Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("Operators have been extracted and written to output_operators.txt successfully.\n");




    return 0;
}