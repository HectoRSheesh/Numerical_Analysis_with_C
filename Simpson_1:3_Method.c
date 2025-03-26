#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate f(z) = 1/z
double Fonksiyon(double z){
    return 1 / z;  // Returns the reciprocal of z
}

// Function to calculate the integral of f(z) = log(z)
double Fonk_Int(double z){
    return log(z);  // Returns the natural logarithm of z
}

// Function to calculate the integral using Simpson's 1/3 rule
double sim13(double B[], double hh, int x){
    int j;
    double IS = B[0] + B[x - 1];  // Initialize with the first and last terms
    for (j = 1; j <= x - 2; j = j + 2){
        IS = IS + 4 * B[j];  // Multiply odd-indexed terms by 4 and add
    }
    for (j = 2; j <= x - 3; j = j + 2){
        IS = IS + 2 * B[j];  // Multiply even-indexed terms by 2 and add
    }
    IS = (hh / 3) * IS;  // Multiply the sum by h/3
    return IS;
}

int main(void){
    // Variable declarations
    double a = 1, b = 2, h, i, gercek_deger, mutlak_hata, Y[11];
    int n = 10, j = 0;

    h = (b - a) / n;  // Calculate the step size (h)
    i = a;

    // Compute function values for each subinterval
    while (i <= b){
        printf("F(%.2lf) = %lf\n", i, Fonksiyon(i));
        Y[j] = Fonksiyon(i);  // Store function values in array Y
        i = i + h;  // Increment by the step size
        j++;
    }

    // Calculate the exact value of the integral
    gercek_deger = Fonk_Int(b) - Fonk_Int(a);
    printf("The exact value of the integral = %lf\n", gercek_deger);
    
    // Calculate the integral using Simpson's 1/3 rule
    double IDS13 = sim13(Y, h, n + 1);
    printf("Simpson's (1/3) method = %lf\n", IDS13);
    
    // Calculate the absolute error for Simpson's 1/3 rule
    mutlak_hata = fabs(gercek_deger - IDS13);
    
    // Print the results
    printf("\n");
    printf("Absolute error (Simpson's 1/3 method) = %lf\n", mutlak_hata);
    printf("\n");
    printf("Relative percentage error (Simpson's 1/3 method) = %lf\n", (mutlak_hata / fabs(gercek_deger)) * 100);
    
    return 0;  // Exit the program
}

