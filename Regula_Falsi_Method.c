#include<stdio.h>
#include<math.h>
#define hata 0.0001  // Define the tolerance for approximation (error)

float F(float x){
    return x + log(x) - 5;  // Function to calculate f(x), combining x, natural logarithm of x, and a constant
}

int main(void){
    float a, b, x0, x1;  // Variables for the interval [a, b] and intermediate values
    int i = 0;  // Counter for the number of iterations
    
    // Prompt user to input the starting interval [a, b]
    printf("Enter the value of a: ");
    scanf("%f", &a);
    printf("Enter the value of b: ");
    scanf("%f", &b);
    
    // Check if the function values at a and b have opposite signs
    if ((F(a) * F(b) >= 0)){
        printf("No guaranteed root exists between %.4f and %.4f...", a, b);
        return 0;  // Exit if there's no sign change
    }
    
    // Calculate the first approximation using the Regula Falsi method
    x0 = (a * F(b) - b * F(a)) / (F(b) - F(a));
    
    // Iterate to refine the root approximation
    do{
        i++;  // Increment the iteration counter
        printf("Approximate root at step %d= %.4f\t ", i, x0);
        x1 = x0;  // Store the current approximation
        if (F(x0) * F(a) < 0)  // Check which subinterval contains the root
            b = x0;  // Update the end of the interval
        else
            a = x0;  // Update the start of the interval
        printf("New interval= [%.4f, %.4f]\n", a, b);
        // Calculate the next approximation using the Regula Falsi method
        x0 = (a * F(b) - b * F(a)) / (F(b) - F(a));
    }while (fabs(x0 - x1) > hata);  // Repeat until the error is within tolerance
    
    // Output the final results
    printf("The approximate root was calculated at step %d:\n", ++i);
    printf("Approximate root = %.4f\n", x0);
    printf("f(%.4f) = %.4f\n", x0, F(x0));
    
    return 0;  // Exit the program
}

