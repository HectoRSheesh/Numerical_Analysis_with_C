#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the actual value of f(x)
float f(float a){
    return 1 / a;  // Returns the reciprocal of the input
}

int main(void){
    
    float *x, *y, p, c, xt;  // Arrays for x and y points, interpolation value (p), term coefficient (c), and input point (xt)
    char cevap;  // Variable to store the user's response (unused in this code)
    int i, j, n;  // Loop variables and number of data points
    
    // Introduction and input for number of data points
    printf("Lagrange Interpolation\n");
    printf("\nHow many data points are there? ---> ");
    scanf("%d", &n);
    
    // Allocate memory for arrays to store x and y values
    x = (float *) malloc(n * sizeof(float));
    y = (float *) malloc(n * sizeof(float));
    
    // Input x and y values for the data points
    for (i = 0; i < n; i++){
        printf("Enter the x value for measurement %d: ", i + 1);
        scanf("%f", &x[i]);
        printf("Enter the y value for measurement %d: ", i + 1);
        scanf("%f", &y[i]);
    }
    
    // Input the x value for which y=f(x) is to be estimated
    printf("Enter the x value for which y=f(x) will be estimated: ");
    scanf("%f", &xt);
    
    // Perform Lagrange Interpolation to calculate the approximate value of y at xt
    p = 0;  // Initialize the result of the interpolation
    for (i = 0; i < n; i++){
        c = 1;  // Initialize the coefficient for the current term
        for (j = 0; j < n; j++)
            if (i != j) {  // Ensure we skip the same index
                c *= (xt - x[j]) / (x[i] - x[j]);  // Compute the term's coefficient
            }
        p += y[i] * c;  // Add the term to the result
    }
    
    // Print the results
    printf("\nEstimated value= %f\n", p);  // Display the interpolated value
    printf("\nActual value= %f\n", f(xt));  // Display the actual function value
    printf("\nError= %f\n", fabs(f(xt) - p));  // Display the error (absolute difference)
    
    return 0;  // Exit the program
}

