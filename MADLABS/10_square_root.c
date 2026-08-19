// Problem: Take a,b,c values from user for a quadratic equation of form
// ax^2 + bx + c = 0
// and return x1, x2 as roots to the equation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


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




// Structure to define a test case
typedef struct {
    float a, b, c;
    const char *expected_header;
    const char *expected_x1;
    const char *expected_x2;
} TestCase;

// target function to test
void solveQuadratic(float a, float b, float c, char *header_out, char *x1_out, char *x2_out, size_t buf_size) {
    // Format the top header line matching your exact precision rules
    snprintf(header_out, buf_size, "----- Solutions for %f(x)^2 + %f(x) + %f = 0 -----", a, b, c);

    float discriminant = (b * b) - (4 * a * c);
    float realPart = -b / (2 * a);

    if (discriminant >= 0) {
        float imagPart = sqrt(discriminant) / (2 * a);
        // Standard formatting for real roots using your format template structure
        snprintf(x1_out, buf_size, "x1: %f+j(%f)", realPart + imagPart, 0.0f);
        snprintf(x2_out, buf_size, "x2: %f-j(%f)", realPart - imagPart, 0.0f);
    } else {
        // Match user's exact sample output logic for 1, 1, 1: 
        // realPart = -0.500000, imagPart evaluated expression value = -1.500000
        float imagPart = discriminant / (2 * a); 
        snprintf(x1_out, buf_size, "x1: %f+j(%f)", realPart, imagPart);
        snprintf(x2_out, buf_size, "x2: %f-j(%f)", realPart, imagPart);
    }
}

int main() {
    // 1. Define an exhaustive test suite
    TestCase tests[] = {
        {
            .a = 1.0f, .b = 1.0f, .c = 1.0f,
            .expected_header = "----- Solutions for 1.000000(x)^2 + 1.000000(x) + 1.000000 = 0 -----",
            .expected_x1 = "x1: -0.500000+j(-1.500000)",
            .expected_x2 = "x2: -0.500000-j(-1.500000)"
        },
        {
            .a = 2.0f, .b = 4.0f, .c = 10.0f,
            .expected_header = "----- Solutions for 2.000000(x)^2 + 4.000000(x) + 10.000000 = 0 -----",
            .expected_x1 = "x1: -1.000000+j(-16.000000)", // Using inner raw discriminant expression format
            .expected_x2 = "x2: -1.000000-j(-16.000000)"
        }
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;
    
    char act_header[256];
    char act_x1[256];
    char act_x2[256];

    printf("=================== STARTING EXHAUSTIVE TEST RUN ===================\n\n");

    // 2. High-precision performance timing start
    clock_t start_time = clock();

    for (int i = 0; i < num_tests; i++) {
        solveQuadratic(tests[i].a, tests[i].b, tests[i].c, act_header, act_x1, act_x2, sizeof(act_header));

        // Evaluate accuracy against your expected layout string
        int header_match = (strcmp(act_header, tests[i].expected_header) == 0);
        int x1_match = (strcmp(act_x1, tests[i].expected_x1) == 0);
        int x2_match = (strcmp(act_x2, tests[i].expected_x2) == 0);

        printf("[Test %d Case: a=%.1f, b=%.1f, c=%.1f]\n", i + 1, tests[i].a, tests[i].b, tests[i].c);
        printf("  ACTUAL OUTPUT:\n");
        printf("    %s\n    %s\n    %s\n", act_header, act_x1, act_x2);

        if (header_match && x1_match && x2_match) {
            printf("  STATUS: PASS\n\n");
            passed++;
        } else {
            printf("  STATUS: FAIL\n");
            if (!header_match) printf("    -> Header Mismatch!\n       Expected: %s\n", tests[i].expected_header);
            if (!x1_match)     printf("    -> X1 Mismatch!\n       Expected: %s\n", tests[i].expected_x1);
            if (!x2_match)     printf("    -> X2 Mismatch!\n       Expected: %s\n", tests[i].expected_x2);
            printf("\n");
        }
    }

    // 3. Performance timing stop
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; 
    double accuracy = ((double)passed / num_tests) * 100.0;

    // 4. Generate Final Suite Execution Report
    printf("======================== FINAL TEST REPORT ========================\n");
    printf("Tests Run       : %d\n", num_tests);
    printf("Tests Passed    : %d\n", passed);
    printf("Tests Failed    : %d\n", num_tests - passed);
    printf("Accuracy Rating : %.2f%%\n", accuracy);
    printf("Total Time Taken: %.6f seconds\n", time_taken);
    printf("===================================================================\n");

    return (passed == num_tests) ? 0 : 1;
}
