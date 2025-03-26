#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute f(z) = 1 / (1 + z^2)
double Fonksiyon(double z){
    return 1 / (1 + pow(z, 2));  // Returns the value of the function at z
}

// Function to compute the exact integral of f(z)
double Fonk_Int(double z){
    return atan(z);  // Returns the arctangent of z (integral of the function)
}

// Function to compute the integral using Simpson's 3/8 Rule
double sim38(double B[], double hh, int x){
    int j;
    double IS = B[0] + B[x - 1];  // Initialize with the first and last terms

    // Add terms multiplied by 3 (for odd indices)
    for (j = 1; j <= x - 3; j = j + 3){
        IS = IS + 3 * B[j];
    }

    // Add terms multiplied by 3 (for even indices)
    for (j = 2; j <= x - 2; j = j + 3){
        IS = IS + 3 * B[j];
    }

    // Add terms multiplied by 2 (for indices divisible by 3)
    for (j = 3; j <= x - 4; j = j + 3){
        IS = IS + 2 * B[j];
    }

    IS = ((3 * hh) / 8) * IS;  // Multiply the sum by (3h/8) for Simpson's 3/8 rule
    return IS;
}

int main(void){
    // Variable declarations
    double a = 0, b = 6, h, i, gercek_deger, mutlak_hata, Y[7];
    int n = 6, j = 0;

    h = (b - a) / n;  // Calculate the step size (h)
    i = a;

    // Compute function values for each interval and store in array Y
    while (i <= b){
        printf("F(%.2lf) = %lf\n", i, Fonksiyon(i));
        Y[j] = Fonksiyon(i);  // Store function value at z = i
        i = i + h;  // Increment by step size
        j++;
    }

    // Calculate the exact value of the integral
    gercek_deger = Fonk_Int(b) - Fonk_Int(a);
    printf("The exact value of the integral = %lf\n", gercek_deger);

    // Calculate the integral using Simpson's 3/8 Rule
    double IDS38 = sim38(Y, h, n + 1);
    printf("Simpson's (3/8) method = %lf\n", IDS38);

    // Calculate the absolute error for Simpson's 3/8 Rule
    mutlak_hata = fabs(gercek_deger - IDS38);

    // Print the results
    printf("\n");
    printf("Absolute error (Simpson's 3/8 method) = %lf\n", mutlak_hata);
    printf("\n");
    printf("Relative percentage error (Simpson's 3/8 method) = %lf\n", (mutlak_hata / fabs(gercek_deger)) * 100);

    return 0;  // Exit the program
}

