#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // We have a text input with multiple lines
    FILE *input_file;
    char currChar;
    char char1;
    char char2;
    int sumResult = 0;

    input_file = fopen("test.txt", "rt");

    if(input_file != NULL){
        while((currChar = fgetc(input_file)) != EOF){
            if(currChar == '\n'){
                printf("%c%c\n", char1, char2);
                int dec = (char1 - '0') * 10;
                int unit = (char2 - '0');
                sumResult = sumResult + dec + unit;
                char1 = '\0';
                char2 = '\0';
            }
            if(isdigit(currChar)){
                    if(char1 == '\0'){
                        char1 = currChar;
                        char2 = currChar;
                    }
                    else{
                        char2 = currChar;
                    }
            }
            
        }
        printf("%d\n", sumResult);
    }

    fclose(input_file);
    // We want for each line to find the first and last digit in the line and put them together
    // If there's only one digit it is doubled
    // Finally for all those values, we want to sum them up and display the result
}
