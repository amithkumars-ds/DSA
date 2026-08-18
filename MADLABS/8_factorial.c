// Take a number 'n' as input from user and print the factorial of that number


#include<stdio.h>
#include <time.h>

int main(){
    // initialising stuff
    int num;
    unsigned long long factorial = 1;

    // reading inputs from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    clock_t start = clock(); // start timer
   
    // performing factorial operation
    while(num>1){
        factorial = factorial * num;
        num--;
    }
    
    clock_t end = clock(); // end timer
    double elapsed_time = (double)(end-start)/CLOCKS_PER_SEC;

    // displaying results
    printf("Time Taken: %.6f seconds\n",elapsed_time);
    printf("Factorial of %d is: %llu\n",num,factorial);

    return 0;
}
