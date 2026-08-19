// Problem: Write a C program that takes an array of 10 integers and removes all duplicate values
// keeping only the first occurrence of each value.
// Requirements:
// 1. Take 10 integers as input
// 2. Do not use sorting
// 3. Do not use recursion
// 4. Do not use library functions for duplicate removal
// 5. Preserve the original order of the first occurrence
// 6. Print the resulting array and its new size.

#include <stdio.h>
#define MAX_SIZE 10

int main(){
    // initialising stuff
    int numbers[MAX_SIZE];
    int unique[MAX_SIZE];
    int current_pos = 0;

    // reading inputs from the user
    printf("Enter 10 numbers: \n");
    for (int i = 0; i < MAX_SIZE; i++){
        scanf("%d", &numbers[i]);
    }

    // removing duplicate values
    for (int i = 0; i < MAX_SIZE; i++){
        int already_exists = 0;

        for (int j = 0; j < current_pos; j++){
            if (unique[j] == numbers[i]){
                already_exists = 1;
                break;
            }
        }

        if (!already_exists){
            unique[current_pos] = numbers[i];
            current_pos++;
        }
    }

    // displaying results
    printf("Unique elements:\n");

    for (int i = 0; i < current_pos; i++){
        printf("%d\n", unique[i]);
    }

    printf("New size: %d\n", current_pos);

    return 0;
}
