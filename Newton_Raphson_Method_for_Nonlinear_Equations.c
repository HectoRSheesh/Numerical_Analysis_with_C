#include<stdio.h>
#include<math.h>
#define hata 0.001  // Define the tolerance for approximation (error)

// Function to calculate f(x, y)
float F(float x, float y){
    return pow(x, 2) + x * y - 10;  // First equation of the system
}

// Function to calculate g(x, y)
float G(float x, float y){
    return y + 3 * x * pow(y, 2) - 57;  // Second equation of the system
}

// Partial derivative of f(x, y) with respect to x
float FX(float x, float y){
    return 2 * x + y;  // ∂f/∂x
}

// Partial derivative of f(x, y) with respect to y
float FY(float x, float y){
    return x;  // ∂f/∂y
}

// Partial derivative of g(x, y) with respect to x
float GX(float x, float y){
    return 3 * pow(y, 2);  // ∂g/∂x
}

// Partial derivative of g(x, y) with respect to y
float GY(float x, float y){
    return 1 + 6 * x * y;  // ∂g/∂y
}

int main(void){
    
    float x0 = 1.5, x1, y0 = 3.5, y1, x, y;  // Initial guesses for x and y, and variables for calculations
    int i = 0;  // Counter for iterations
    printf("Starting point of the method= (%.3f, %.3f)\n", x0, y0);

    do{
        x = x0;  // Store the previous value of x
        y = y0;  // Store the previous value of y
        // Update x using the formula derived from the system of equations and their derivatives
        x1 = x0 - ((F(x0, y0) * GY(x0, y0) - G(x0, y0) * FY(x0, y0)) /
                   (FX(x0, y0) * GY(x0, y0) - GX(x0, y0) * FY(x0, y0)));
        // Update y using the formula derived from the system of equations and their derivatives
        y1 = y0 + ((F(x0, y0) * GX(x0, y0) - G(x0, y0) * FX(x0, y0)) /
                   (FX(x0, y0) * GY(x0, y0) - GX(x0, y0) * FY(x0, y0)));
        x0 = x1;  // Update x0 with the new value of x
        y0 = y1;  // Update y0 with the new value of y
        i++;  // Increment iteration counter
        // Print the approximate values of x and y at each step
        printf("Approximate values at step %d= (%.3f, %.3f)\n", i, x1, y1);
    }while ((fabs(x1 - x) > hata) || (fabs(y1 - y) > hata));  // Continue until the error in x and y is within tolerance
    
    // Print the final approximate root values
    printf("Approximate root = (%.3f, %.3f)\n", x1, y1);
    // Print the values of f(x, y) and g(x, y) at the approximate roots
    printf("f(%.3f, %.3f)= %.3f\n", x1, y1, F(x1, y1));
    printf("g(%.3f, %.3f)= %.3f\n", x1, y1, G(x1, y1));
    
    return 0;  // Exit the program
}

