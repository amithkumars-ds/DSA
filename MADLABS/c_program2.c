#include <stdio.h>
#include <time.h>

int main(){
    clock_t global_start = clock();

    int size=10;
    int in[size];

    printf("Enter 10 integers: \n");

    for (int i=0; i<size; i++){
        scanf("%d",&in[i]);
    }

    printf("The elements of array are: ");
    for(int i=0; i<size; i++){
        printf("%d ", in[i]);
    }
    printf("\n");

    // time start
    clock_t start = clock();

    // array reversal by swapping elements
    int temp;
    for(int i=0; i<size/2; i++){
        temp = in[i];
        in[i] = in[size - 1 -i];
        in[size - 1 - i] = temp;
    }

    // time end
    clock_t end = clock();
    double lapsed_time = (double)(end-start)/CLOCKS_PER_SEC;
    double global_time = (double)(end-global_start)/CLOCKS_PER_SEC;

    // displaying results
    printf("\nTotal Execution Time: %.6f seconds\n", global_time);
    printf("\nTime taken for execution: %.6f seconds\n", lapsed_time);
    printf("The elements of reversed array are: ");
    for(int i=0; i<size; i++){
        printf("%d ", in[i]);
    }


    return 0;
}
