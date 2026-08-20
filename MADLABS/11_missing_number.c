// Problem: Write a C program that takes an array containing 'n-1' distinct
// integers from 1 to n, with exactly one number missing nuber.
// Requirements:
// 1. Take 'n' as input
// 2. Take 'n-1' integers as input
// 3. Numbers as distinct
// 4. Numbers range from 1 to n
// 5. Exactly one number is missing
// 6. Do not sort the array
// 7. Do not use recursion
// 8. Do not use library functions


#include <stdio.h>

int main(){
    // init stuff
    int n;
    int expected, missing;
    int actual = 0;
    
    // reading inputs from the user
    printf("Enter n: ");
    scanf("%d",&n);

    int nums[n-1];
    printf("Enter n-1 numbers: \n");
    for(int i=0; i<n-1; i++){
        scanf("%d",&nums[i]);
    }

    // find the missing number
    expected = (0.5)*(n*(n+1));
    for(int i=0;i<n-1;i++){
        actual = actual + nums[i];
    }
    missing = expected - actual;

    printf("Missing number is : %d\n",missing);

    return 0;
}
