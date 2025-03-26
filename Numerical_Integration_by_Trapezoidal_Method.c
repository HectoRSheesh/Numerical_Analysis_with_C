#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the function value f(z) = 1/z
double Fonksiyon(double z){
    return 1 / z;  // Returns the reciprocal of z
}

// Function to calculate the integral of f(z) = log(z)
double Fonk_Int(double z){
    return log(z);  // Returns the natural logarithm of z
}

// Function to calculate the lower sum (underestimate) for integration
double alt(double B[], double hh, int x){
    int j;
    double IA = 0;
    for (j = 0; j <= x - 2; j++){  // Sum up all terms except the last
        IA = IA + B[j];
    }
    IA = hh * IA;  // Multiply by step size (h)
    return IA;
}

// Function to calculate the upper sum (overestimate) for integration
double ust(double B[], double hh, int x){
    int j;
    double IU = 0;
    for (j = 1; j <= x - 1; j++){  // Sum up all terms except the first
        IU = IU + B[j];
    }
    IU = hh * IU;  // Multiply by step size (h)
    return IU;
}

// Function to calculate the trapezoidal approximation for integration
double yamuk(double B[], double hh, int x){
    int j;
    double IY = 0;
    for (j = 1; j <= x - 2; j++){  // Sum up all terms excluding the endpoints
        IY = IY + 2 * B[j];
    }
    IY = IY + B[0] + B[x - 1];  // Add the first and last terms
    IY = (hh / 2) * IY;  // Multiply by (h/2)
    return IY;
}

int main(void){
    // Variable declarations
    double a = 1, b = 2, h, i, gercek_deger, mutlak_hata1, mutlak_hata2, mutlak_hata3, Y[11];
    int n = 10, j = 0;

    h = (b - a) / n;  // Calculate step size (h)
    i = a;
    
    // Calculate function values at intervals of h and store them in array Y
    while (i <= b){
        printf("F(%.2lf) = %lf\n", i, Fonksiyon(i));
        Y[j] = Fonksiyon(i);
        i = i + h;
        j++;
    }

    // Calculate the exact value of the integral
    gercek_deger = Fonk_Int(b) - Fonk_Int(a);
    printf("The exact value of the integral = %lf\n", gercek_deger);
    
    // Calculate approximations using lower sum, upper sum, and trapezoidal method
    double IDA = alt(Y, h, n + 1);
    printf("Sum of lower rectangles = %lf\n", IDA);
    
    double IDU = ust(Y, h, n + 1);
    printf("Sum of upper rectangles = %lf\n", IDU);
    
    double IDY = yamuk(Y, h, n + 1);
    printf("Sum of trapezoids = %lf\n", IDY);
    
    // Calculate the absolute errors for each method
    mutlak_hata1 = fabs(gercek_deger - IDA);  // Error for lower sum
    mutlak_hata2 = fabs(gercek_deger - IDU);  // Error for upper sum
    mutlak_hata3 = fabs(gercek_deger - IDY);  // Error for trapezoidal method

    // Print the errors
    printf("\n");
    printf("Absolute error (Lower rectangles) = %lf\n", mutlak_hata1);
    printf("Absolute error (Upper rectangles) = %lf\n", mutlak_hata2);
    printf("Absolute error (Trapezoids) = %lf\n", mutlak_hata3);
    printf("\n");

    // Print the relative percentage errors for each method
    printf("Relative percentage error (Lower rectangles) = %lf\n", (mutlak_hata1 / fabs(gercek_deger)) * 100);
    printf("Relative percentage error (Upper rectangles) = %lf\n", (mutlak_hata2 / fabs(gercek_deger)) * 100);
    printf("Relative percentage error (Trapezoids) = %lf\n", (mutlak_hata3 / fabs(gercek_deger)) * 100);
    
    return 0;  // Exit the program
}

