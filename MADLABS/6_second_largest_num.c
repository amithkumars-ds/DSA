// Write a C program that finds the second-largest number amoong 5 integers.
// Requirements:
// 1. Take 5 ntegers as input
// 2. Do not use arrays
// 3. Do not sort the numbers
// 4. Do not use library functions such as qsort()
// 5. If all 5 numbers are equal, report that there is no second-largest distinct value

#include <stdio.h>

int main(){
    // initialising stuff
    int n1, n2, n3, n4, n5;
    int found_second = 0;

    // taking inputs from user
    printf("Enter 5 numbers: \n");
    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);
    scanf("%d", &n4);
    scanf("%d", &n5);

    // performing comparison to find the second largest number
    int largest = n1;
    int second_largest;

    // ------process n2------
    if (n2 > largest){
        second_largest = largest;
        largest = n2;
        found_second = 1;
    }else if (n2 < largest && (!found_second ||n2  > second_largest)){
        second_largest = n2;
        found_second = 1;
    }

    // ------process n3------
    if (n3 > largest){
        second_largest = largest;
        largest = n3;
        found_second = 1;
    }else if (n3 < largest && (!found_second || n3 > second_largest)){
        second_largest = n3;
        found_second = 1;
    }

    // ------process n4------
    if (n4 > largest){
        second_largest = largest;
        largest = n4;
        found_second = 1;
    }else if (n4 < largest && (!found_second || n4 > second_largest)){
        second_largest = n4;
        found_second = 1;
    }

    // ------process n5-----
    if (n5 > largest){
        second_largest = largest;
        largest = n5;
        found_second = 1;
    }else if (n5 < largest && (!found_second || n5 > second_largest)){
        second_largest = n5;
        found_second = 1;
    }


    // displaying results
    if (found_second==0){
            printf("All numbers are same, no second largest number\n");
    }else{
        printf("The second largest number is: %d\n",second_largest);
    }


    return 0;
}
