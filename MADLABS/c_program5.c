// Write a C program that cheks whether an integer is a palindrome
// Requirements
// Handle negative numbers
// Note: Do not use arrays, strings or recursion
// Do not convert the number to another type

#include <stdio.h>

int main(){
    // initialising stuff
    int n, digit;
    int reversed = 0;
    int sign = 1;
    char *is_palindrome = "Palindrome";

    // taking input from user
    printf("Enter a number: ");
    scanf("%d",&n);

    // handling negative numbers
    if(n<1){
        sign = -1;
        n = -n;
    }

    // reversing the number
    int original = n;
    while(n>0){
        digit = n%10;
        reversed = reversed*10 + digit;
        n =n/10;
    }

    // checking if the number is a palindrome
    if(original!=reversed){
        is_palindrome = "Not a Palindrome";
    }

    // displaying results
    printf("The number is: %s\n",is_palindrome);

    return 0;
}
