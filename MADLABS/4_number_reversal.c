// Write a C program that takes an integer 'n' and reverses it digits
// input: 12345 -> output: 54321
// Do not use arrays or strings
// handle 0 correctly
// handle negative numbers correctly

#include <stdio.h>
#include <time.h>

int main(){
    int n, digit;
    int sign = 1;
    int reversed = 0;

    printf("Enter a number: ");
    scanf("%d", &n);
    
    if(n<0){
        sign = -1;
        n = -n;
    }
    
    int original = n;
    while(n>0){
        digit = n%10;
        reversed = reversed * 10 + digit;
        n = n/10;
    }

    reversed = reversed * sign;
    printf("Reversed number is: %d\n",reversed);

    return 0;
}
