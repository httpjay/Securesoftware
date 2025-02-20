#include <stdio.h>

void noncompliant_example(int x) {
    if (x & 1 == 0) { // Noncompliant: Misinterpreted due to operator precedence
        printf("Even number (Incorrect evaluation)\n");
    } else {
        printf("Odd number (Incorrect evaluation)\n");
    }
}

void compliant_example(int x) {
    if ((x & 1) == 0) { // Compliant: Proper use of parentheses
        printf("Even number (Correct evaluation)\n");
    } else {
        printf("Odd number (Correct evaluation)\n");
    }
}

int main() {
    int x = 0;
    
    printf("Noncompliant example:\n");
    noncompliant_example(x);

    printf("\nCompliant example:\n");
    compliant_example(x);

    return 0;
}
