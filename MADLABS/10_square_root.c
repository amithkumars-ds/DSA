// Problem: Take a,b,c values from user for a quadratic equation of form
// ax^2 + bx + c = 0
// and return x1, x2 as roots to the equation

#include <stdio.h>

int squareRoot(float a, float b, float c){
    // init values
    float D, denom;
    float x1, x2;

    // computing D
    D = (b*b)-(4*a*c);


    // finding roots
    // ----- if D>0 -----
    if(D>0){
        x1 = (-b+(D))/(2*a);
        x2 = (-b-(D))/(2*a);

        printf("----- Solutions for %f(x)^2 + %f(x) + %f = 0 -----\n",a,b,c);
        printf("x1: %f\n",x1);
        printf("x2: %f\n",x2);
    }else{
        denom = 2*a;
        float left = -b/denom;
        float right = D/denom;

        printf("----- Solutions for %f(x)^2 + %f(x) + %f = 0 -----\n",a,b,c);
        printf("x1: %f+j(%f)\n",left,right);
        printf("x2: %f-j(%f)\n",left,right);
    }


    return 0;
}


int main(){
    squareRoot(1,1,1);

    return 0;
}
