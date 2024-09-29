#include <stdio.h>  
#include <string.h> // for string functions like strlen()

// Function to swap two characters
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort characters using bubble sort
void bubbleSort(char arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char str[1000];  // array to hold the string from the file
    int length;

    // Open the input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Could not open input.txt\n");
        return 1;
    }

    // Read the string from the file
    fgets(str, sizeof(str), inputFile);
    fclose(inputFile);

    // Get the length of the string
    length = strlen(str);

    // Sort the string using bubble sort
    bubbleSort(str, length);

    // Open the output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Could not open output.txt\n");
        return 1;
    }

    // Write the sorted string to the output file
    fputs(str, outputFile);
    fclose(outputFile); // close the file

    printf("Sorting done! Check output.txt for the result.\n");

    return 0;
}
