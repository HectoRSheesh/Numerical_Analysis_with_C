#include<stdio.h>
#include<math.h>

// Function to calculate f(x)
float F(float x){
    return pow(x,3) - 20;  // Function definition: f(x) = x^3 - 20
}

int main(void){
    float x0 = 2.5, x1 = 3, x2, x;  // Initial guesses (x0, x1) and variables for calculations
    int i = 0;  // Counter for iterations
    printf("Starting points of the method: x1=%.4f and x2=%.4f\n", x0, x1);

    do{
        x = x1;  // Store the current value of x1
        // Compute the new approximation using the Secant Method formula
        x2 = ((x0 * F(x1)) - (x1 * F(x0))) / (F(x1) - F(x0));
        x0 = x1;  // Update x0 to the previous value of x1
        x1 = x2;  // Update x1 to the newly computed approximation
        i++;  // Increment iteration counter
        printf("Approximate root at step %d= %.4f\n", i, x2);
    }while (i < 2);  // Stop after 2 iterations (currently set as the stopping condition)

    // Print the final approximate root and the value of f(x) at the root
    printf("f(%.4f) = %.4f\n", x2, F(x2));
    return 0;  // Exit the program
}
