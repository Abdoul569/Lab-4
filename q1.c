#include<stdio.h>
int main(){
    FILE *inputFile, *outputFile; // File pointers for input and output files
    char ch;
    inputFile = fopen("input.txt", "r");
    if(inputFile == NULL){
        printf("Error: cannot input file\n"); // If the file does not exist, it will display an error
        return 1;
    }

    outputFile = fopen("output.txt", "w"); // open output.txt
    if(outputFile == NULL){
        printf("Eror: cannot output file");// If the file does not exist, it will display an error
        return 1;
        fclose(inputFile);
        return 1;
    }
    while((ch = fgetc(inputFile))!= EOF){ // Loop through each character from the input file until EOF is reached
        printf("%c ", ch); // Print each character on the screen
        fputc(ch, outputFile); // write the character to the output file 
    }
    // Close both files 
    fclose(inputFile);
    fclose(outputFile);
    printf("File copied successfully\n");
    return 0;
}
