#include <stdio.h>
#include <ctype.h>  // for toupper() and isalnum()

int isValidIdentifierStart(char ch) {
    // Identifiers must start with a letter or underscore
    return (ch == '_' || isalpha(ch));
}

int isValidIdentifierChar(char ch) {
    // Identifiers can contain letters, digits, or underscores
    return (ch == '_' || isalnum(ch));
}

int main() {
    FILE *inputFile, *outputFile;
    char ch;
    int inIdentifier = 0;  // Flag to check if we're inside an identifier

    
    inputFile = fopen("input.txt", "r"); // Open input file in read mode
    if (inputFile == NULL) {
        printf("Error: cannot open input file\n");
        return 1;
    }


    outputFile = fopen("output_identifiers_uppercase.txt", "w");     // Open output file in write mode
    if (outputFile == NULL) {
        printf("Error: cannot open output file\n");
        fclose(inputFile);
        return 1;
    }

    // Read file character by character
    while ((ch = fgetc(inputFile)) != EOF) {
        if (!inIdentifier) {
            // Check if it's a valid start of an identifier
            if (isValidIdentifierStart(ch)) {
                inIdentifier = 1;
                // Write the first character in uppercase to the output file
                fputc(toupper(ch), outputFile);
            }
        } else {
            // We're inside an identifier, check if it continues
            if (isValidIdentifierChar(ch)) {
                // Convert the character to uppercase and write to output file
                fputc(toupper(ch), outputFile);
            } else {
                // Not a valid identifier character, so end this identifier
                fputc('\n', outputFile);  // End the identifier in the output file
                inIdentifier = 0;
            }
        }
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Identifiers extracted and converted to uppercase successfully.\n");

    return 0;
}
