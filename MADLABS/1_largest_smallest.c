#include <stdio.h>
#include <time.h>

int main(){
    int n[10];
    printf("Enter 10 intergers: \n");
    
    // loop to read 10 values from user
    for (int i=0; i<10; i++){
        scanf("%d", &n[i]);
    }

    // time start
    clock_t start = clock();
    
    // find the largest number in the array
    int max=n[0];
    for (int i=0; i<10; i++){
        if(n[i]>max){
            max=n[i];
        };
    }
    
    int min=n[0];
    for (int i=0; i<10; i++){
        if(n[i]<min){
            min=n[i];
        };
    }
    
    // clock end
    clock_t end = clock();
    double elapsed = (double)(end-start)/CLOCKS_PER_SEC;


    // display results
    printf("Time Elapsed: %.6f seconds\n", elapsed);
    printf("Largest number in the element is: %d\n",max);
    printf("Smallest number in the element is: %d\n",min);

    return 0;
}
