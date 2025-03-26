#include<stdio.h>
#include<math.h>
#define hata 0.0001  // Define the tolerance for approximation (error)

// Function to calculate f(x)
float F(float x){
    return 2 * exp(x) - log(x) + x - 13.31;  // Function: combination of exponential, logarithmic, and linear terms
}

// Function to calculate f'(x) (first derivative)
float FT(float x){
    return 2 * exp(x) - (1 / x) + 1;  // Derivative of f(x)
}

// Function to calculate f''(x) (second derivative)
float FTT(float x){
    return 2 * exp(x) + (1 / pow(x, 2));  // Second derivative of f(x)
}

int main(void){
    float a1 = 0.0, b1 = 0.0, a0, b0;  // Variables for interval endpoints and new approximations
    int i = 0;  // Counter for iterations
    
    // Prompt user to enter the interval [a0, b0]
    printf("Enter the value of a: ");
    scanf("%f", &a0);
    printf("Enter the value of b: ");
    scanf("%f", &b0);
    
    // Check if the function values at a0 and b0 have opposite signs
    if ((F(a0) * F(b0) >= 0)){
        printf("No guaranteed root exists between %.4f and %.4f...", a0, b0);
        return 0;  // Exit if there's no sign change
    }

    // Perform iterations to refine the root approximation
    do{
        printf("\n");
        // Print the values of f(a0), f(b0), f'(x), and f''(x)
        printf ("f(%.4f) = %.4f\n", a0, F(a0));
        printf ("f(%.4f) = %.4f\n", b0, F(b0));
        printf ("f''(%.4f) = %.4f\n", a0, FTT(a0));
        printf ("f''(%.4f) = %.4f\n", b0, FTT(b0));
        printf ("f'(%.4f) = %.4f\n", a0, FT(a0));
        printf ("f'(%.4f) = %.4f\n", b0, FT(b0));
        
        // Check which point satisfies the second derivative condition and update approximations
        if ((F(a0) * FTT(a0)) > 0){
            a1 = a0 - (F(a0) / FT(a0));  // Update using tangent method
            b1 = ((b0 * F(a0)) - (a0 * F(b0))) / (F(a0) - F(b0));  // Update using Regula Falsi method
            printf("Tangent drawn from point (%.4f, f(%.4f))...\n", a0, a0);
        }
        if ((F(b0) * FTT(b0)) > 0){
            b1 = b0 - (F(b0) / FT(b0));  // Update using tangent method
            a1 = ((a0 * F(b0)) - (b0 * F(a0))) / (F(b0) - F(a0));  // Update using Regula Falsi method
            printf("Tangent drawn from point (%.4f, f(%.4f))...\n", b0, b0);
        }
        
        // Update interval endpoints
        a0 = a1;
        b0 = b1;
        i++;  // Increment iteration counter
        printf("New interval at step %d = (%.4f , %.4f)\n", i, a1, b1);
        printf("\n");
    }while (fabs(a1 - b1) > hata);  // Continue until the error is within tolerance
    
    // Print the final approximate root and the value of f(x) at the root
    printf("The approximate root was calculated at step %d:\n", i);
    printf("Approximate root = %.4f\n", a1);
    printf("f(%.4f) = %.4f\n", a1, F(a1));
    
    return 0;  // Exit the program
}

