//
//  Newton_Raphson_Algorithm.c
//
//
//  Created by Ozan Bali on 26.03.2025.


#include <stdio.h>
#include <math.h>

#define hata 0.00001  // Define the error tolerance for the iteration

// Function to calculate the value of f(x)
float F(float x){
    return exp(x)-3*x;  // Exponential function minus 3 times x
}

// Function to calculate the derivative of f(x), f'(x)
float FT(float x){
    return exp(x)-3;  // Derivative of the function
}

int main(void){
    
    float x0=0, x;  // Initial guess (x0) and a variable (x) for previous value
    int i=0;  // Counter to track the number of iterations
    printf("Starting point of the method= %.6f\n",x0);

    do{
        x=x0;  // Store the current value of x0
        x0=x-F(x)/FT(x);  // Update x0 using Newton-Raphson formula
        i++;  // Increment iteration counter
        printf("Approximation value at step %d= %.6f\n",i,x0);
    }while (fabs(x0-x)>hata);  // Repeat until the difference is less than the error tolerance

    printf("Approximate root = %.6f\n",x0);  // Print the approximate root
    printf("f(%.6f)= %.6f\n",x0,F(x0));  // Print the value of the function at the approximate root
}
