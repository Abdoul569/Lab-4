#include<stdio.h>

// Define a constant for the maximum number of decimal numbers to store
#define Max_Numbers 100

// Function to sort an array of floats using the bubble sort algorithm
void bubblesort(float arr[], int n) {
    int i, j;
    float temp;
    
    // Outer loop to iterate over the array
    for (i = 0; i < n-1; i++) {
        // Inner loop to compare adjacent elements
        for(j = 0; j < n-1; j++) {
            // Swap elements if the current one is greater than the next
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){

    // Declare file pointers for input and output files
    FILE *file1, *file2, *outputFile;

    // Array to store the numbers from both files
    float Numbers[Max_Numbers];

    // Counter to keep track of the number of elements in the array
    int count = 0;
    float num;

    // Open the first file (decimal1.txt) for reading
    file1 = fopen("decimal1.txt", "r");
    if (file1 == NULL) {
        printf("Error: cannot open decimal1.txt\n");
        return 1; // Exit if the file can't be opened
    }

    // Read all the floating-point numbers from decimal1.txt and store them in the array
    while (fscanf(file1, "%f", &num) == 1) {
        Numbers[count++] = num;
    }

    // Close the first file after reading
    fclose(file1);

    // Open the second file (decimal2.txt) for reading
    file2 = fopen("decimal2.txt", "r");
    if (file2 == NULL) {
        printf("Error: cannot open decimal2.txt\n");
        return 1; // Exit if the file can't be opened
    }

    // Read all the floating-point numbers from decimal2.txt and add them to the array
    while (fscanf(file2, "%f", &num) == 1) {
        Numbers[count++] = num;
    }

    // Close the second file after reading
    fclose(file2);

    // Call the bubble sort function to sort the combined numbers
    bubblesort(Numbers, count);

    // Open the output file (sorted_decimal.txt) for writing
    outputFile = fopen("sorted_decimal.txt", "w");
    if (outputFile == NULL) {
        printf("Error: cannot open sorted_decimal.txt\n");
        return 1; // Exit if the file can't be opened
    }

    // Write the sorted numbers to the output file
    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%.1f ", Numbers[i]);
    }

    // Close the output file after writing
    fclose(outputFile);

    // Print a success message
    printf("Numbers sorted and written to sorted_decimal.txt\n");

    return 0;
}
