//
//  Bisection_Method.c
//
//
//  Created by Ozan Bali on 26.03.2025.
//

#include<stdio.h>
#include<math.h>
#define hata 0.002  // Define the tolerance for approximation (error)

float F(float x){
    return sin(x)+cos(x)-x;  // Function to calculate the value of f(x)
}

int main(void){
    float t;  // Temporary variable (not used)
    float a,b,x,x0,x1;  // Variables for the interval [a, b] and intermediate values
    int i=0;  // Counter for the number of iterations
    printf("Enter the value of a: ");  // Prompt the user for the start of the interval
    scanf("%f", &a);
    printf("Enter the value of b: ");  // Prompt the user for the end of the interval
    scanf("%f", &b);
    
    // Check if the function values at a and b have opposite signs
    if ((F(a) * F(b) >= 0)){
        printf("No guaranteed root exists between %.4f and %.4f...", a, b);
        return 0;  // Exit if there's no sign change
    }
    
    x0 = (a + b) / 2;  // Calculate the midpoint of the interval
    do{
        i++;  // Increment the iteration counter
        printf("Approximate root at step %d= %.4f\t ", i, x0);
        x1 = x0;  // Store the current value of x0
        if (F(x0) * F(a) < 0)  // Check which subinterval contains the root
            b = x0;  // Update the end of the interval
        else
            a = x0;  // Update the start of the interval
        printf("New interval= [%.4f , %.4f]\n", a, b);
        x0 = (a + b) / 2;  // Calculate the new midpoint
    }while (fabs(x0 - x1) > hata);  // Repeat until the error is within tolerance
    
    printf("Exited loop at step %d. Approximate root at step %d= %.4f\n", i + 1, i + 1, x0);
    printf("Approximate root with error %.3f = %.4f\n", hata, x0);
    printf("f(%.4f)= %.3f", x0, F(x0));  // Print the value of the function at the approximate root
    return 0;  // Exit the program
}

