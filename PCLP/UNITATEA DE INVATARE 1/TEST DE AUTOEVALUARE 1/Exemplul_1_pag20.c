#include <stdio.h>

int main() {
    float a, x, b, E;

    // Take user inputs for a, x, and b
    printf("Enter the value of a: ");
    scanf("%f", &a);

    printf("Enter the value of x: ");
    scanf("%f", &x);

    printf("Enter the value of b: ");
    scanf("%f", &b);

    // Calculate E using the formula E = a * x + b - 2.68
    E = a * x + b - 2.68;

    // Output the result
    printf("The result of E = a * x + b - 2.68 is: %.2f\n", E);

    return 0;
}
