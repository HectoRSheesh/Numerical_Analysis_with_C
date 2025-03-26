#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate f(z)
double Fonksiyon(double z){
    return exp(2 * z);  // Returns e^(2z)
}

// Function to calculate the exact derivative f'(z)
double FT(double z){
    return 2 * exp(2 * z);  // Returns 2 * e^(2z)
}

int main(void){
    // Variable declarations for inputs, calculations, and errors
    double x, h, gercek_deger, mutlak_hata1, mutlak_hata2, mutlak_hata3, i;

    // Input step size (h) for differentiation
    printf("Enter the value of h: ");
    scanf("%lf", &h);

    // Input the point x where the derivative will be calculated
    printf("Enter the x value where the first derivative will be calculated: ");
    scanf("%lf", &x);

    // Print the function values in the range [x-h, x+h] at intervals of h
    for (i = x - h; i <= x + h; i = i + h)
        printf("f(%.3lf) = %.3lf\n", i, Fonksiyon(i));

    // Calculate the exact value of the derivative at x
    gercek_deger = FT(x);

    // Calculate the approximate derivatives using different methods
    double birinciTurev_ileri = (Fonksiyon(x + h) - Fonksiyon(x)) / h;  // Forward difference method
    double birinciTurev_geri = (Fonksiyon(x) - Fonksiyon(x - h)) / h;  // Backward difference method
    double birinciTurev_merkezi = (Fonksiyon(x + h) - Fonksiyon(x - h)) / (2 * h);  // Central difference method

    // Calculate the absolute errors for each method
    mutlak_hata1 = fabs(gercek_deger - birinciTurev_ileri);  // Error for forward difference
    mutlak_hata2 = fabs(gercek_deger - birinciTurev_geri);   // Error for backward difference
    mutlak_hata3 = fabs(gercek_deger - birinciTurev_merkezi); // Error for central difference

    // Output the exact derivative, approximations, and errors
    printf("Exact value = %.3lf (first derivative)\n", gercek_deger);
    printf("First derivative = %.3lf (forward difference)\n", birinciTurev_ileri);
    printf("First derivative = %.3lf (backward difference)\n", birinciTurev_geri);
    printf("First derivative = %.3lf (central difference)\n", birinciTurev_merkezi);
    printf("Absolute error (forward difference) = %.3lf\n", mutlak_hata1);
    printf("Absolute error (backward difference) = %.3lf\n", mutlak_hata2);
    printf("Absolute error (central difference) = %.3lf\n", mutlak_hata3);
    
    return 0;  // Exit the program
}

