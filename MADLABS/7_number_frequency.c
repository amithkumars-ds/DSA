// Write a C program that takes an arrray of 10 integers as input &
// counts how many times a given target number occurs
// Requirements:
// 1. take 10 integers as input into an array
// 2. take one additional integer as target
// 3. count how many times the target occurs
// 4. do not use frequency library or built-in functions
// 5. do not use recursion
// 6. do not sort the array

#include <stdio.h>

int main(){
    // initialising stuff
    int numbers[10];
    int target;
    int count = 0;

    // reading inputs from the user
    printf("Enter 10 numbers: \n");
    for (int i=0; i<10; i++){
        scanf("%d",&numbers[i]);
    }

    printf("Enter target: ");
    scanf("%d",&target);

    // counting the frequency of target in numbers
    for (int i=0; i<10; i++){
        if (numbers[i]==target){
            count++;
        }
    }

    // displaying results
    printf("Target: %d occurs %d times in the array\n",target,count);

    return 0;
}
