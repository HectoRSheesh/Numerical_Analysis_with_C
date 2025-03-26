#include<stdio.h>
#include<math.h>
#define hata 0.005  // Define the tolerance for approximation (error)

// Function to calculate f(x, y)
float f(float x, float y){
    return ((0.1) * pow(x, 2)) + ((0.1) * pow(y, 2)) + (0.8) - x;  // Calculates the value of f(x, y)
}

// Function to calculate g(x, y)
float g(float x, float y){
    return ((0.1) * x * pow(y, 2)) + ((0.1) * x) + (0.8) - y;  // Calculates the value of g(x, y)
}

// Function F(x, y) used to update x in iteration
float F(float x, float y){
    return ((0.1) * pow(x, 2)) + ((0.1) * pow(y, 2)) + (0.8);  // Update formula for x
}

// Function G(x, y) used to update y in iteration
float G(float x, float y){
    return ((0.1) * x * pow(y, 2)) + ((0.1) * x) + (0.8);  // Update formula for y
}

int main(void){
    
    float x0 = 0.5, x1, y0 = 0.5, y1;  // Initial guesses for x and y, and variables for updates
    int i = 0;  // Counter for iterations
    
    // Print the starting point of the method
    printf("Starting point of the method= (%.4f, %.4f)\n", x0, y0);
    do{
        x1 = x0;  // Store the previous value of x
        y1 = y0;  // Store the previous value of y
        x0 = F(x1, y1);  // Update x using function F(x, y)
        y0 = G(x1, y1);  // Update y using function G(x, y)
        i++;  // Increment iteration counter
        // Print the approximate values of x and y at each step
        printf("Approximate values at step %d= (%.4f, %.4f)\n", i, x0, y0);
    }while ((fabs(x1 - x0) > hata) || (fabs(y1 - y0) > hata));  // Continue until the error in x and y is within tolerance

    // Print the final approximate root values
    printf("Approximate root x=%.4f\n", x0);
    printf("Approximate root y=%.4f\n", y0);
    // Print the values of f(x, y) and g(x, y) at the approximate roots
    printf("f(%.4f, %.4f)= %.4f\n", x0, y0, f(x0, y0));
    printf("g(%.4f, %.4f)= %.4f\n", x0, y0, g(x0, y0));
    
    return 0;  // Exit the program
}

