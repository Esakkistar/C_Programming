#include <stdio.h>

// Function to compute the Greatest Common Divisor (GCD) using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute the Least Common Multiple (LCM)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1 = 24, num2 = 15;
    int gcd_result, lcm_result;

    // Compute the GCD
    gcd_result = gcd(num1, num2);

    // Compute the LCM
    lcm_result = lcm(num1, num2);

    // Output the results
    printf("The GCD of %d and %d is %d.\n", num1, num2, gcd_result);
    printf("The LCM of %d and %d is %d.\n", num1, num2, lcm_result);

    return 0;
}

