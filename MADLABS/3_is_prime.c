// Take an integer n from user as input
// Print if the number is prime
// If not, print all its factors


#include <stdio.h>
#include <time.h>

int main(){
    int n;
    int is_prime = 1;

    printf("Please enter a number: ");
    scanf("%d", &n);
    
    // start time
    clock_t start = clock();

    if (n<2){
        printf("%d is not a prime number\n",n);
        return 0;
    }


    for (int i=2; i<n; i++){
        if (n%i==0){
            is_prime = 0;
            printf("%d id not prime, one of the factor: %d\n",n,i);
        }
    } 

    if (is_prime){
        printf("%d is a prime number\n",n);
    }

    // end time
    clock_t end = clock();
    double execution_time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Total Time Taken: %.6f seconds\n", execution_time);

    return 0;
}
