// Write a C program that rotates an array of 'n' integers to the right
// by 'k' positions
// Requirements:
// 1. Take 'n' as input
// 2. Take 'n' integers into an array
// 3. Take 'k' as the number of positions to rotate
// 4. Rotate the array to the right
// 5. Do not use another array
// 6. Do not use sorting, recursion
// 7. Handle k>n
// 8. Print the resulting array

#include <stdio.h>

void reverseArray(int *arr, int start, int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main(){
    // init stuff
    int n, k;

    // reading inputs from the user
    printf("Enter n: ");
    scanf("%d",&n);
    int nums[n];

    printf("Enter n numbers: \n");
    for(int i=0; i<n; i++){
    scanf("%d",&nums[i]);
    }

    printf("\nEnter k: ");
    scanf("%d",&k);

    // verify that k<n otherwise %
    k = k%n;

    // algorithm
    reverseArray(nums,0,n-1);     // 1. reverse the entire array

    // 2. reverse the first 'k' elements
    reverseArray(nums,0,k-1);


    // 3. reverse the remaining 'n-k' elements
    reverseArray(nums,k,n-1);

    // display results to the user
    printf("Elements of an array reversed are : ");
    for(int i=0; i<n; i++){
        printf("%d ", nums[i]);
    }
    print("\n")

    return 0;
}
