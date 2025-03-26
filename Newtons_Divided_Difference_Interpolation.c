#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int m, n, i, j;  // Loop variables and number of points
    printf("Enter the number of points ---> ");
    scanf("%d", &n);
    
    // Declare arrays to store x and y values, and variables for calculations
    float X[n], Y[n][n], s, bx;  // X array (independent variable), Y array (divided difference table), result (s), and input x value (bx)
    printf("Enter the x value for which you want to find the approximate result ---> ");
    scanf("%f", &bx);
    
    // Input x and y values for the data points
    for (i = 0; i < n; i++){
        printf("Enter the x value for point %d: ", i + 1);
        scanf("%f", &X[i]);
        printf("Enter the y value for point %d: ", i + 1);
        scanf("%f", &Y[i][0]);  // y values are stored in the first column of Y
    }
    
    // Compute the divided difference table
    for (i = 1; i < n; i++){
        for (j = 0; j < n - i; j++){
            Y[j][i] = (Y[j + 1][i - 1] - Y[j][i - 1]) / (X[i + j] - X[j]);  // Formula for divided differences
        }
    }
    
    // Print the divided difference table
    printf("\nDivided Difference Table\n");
    printf(" xi -yi=f(xi)");
    
    for (i = 0; i < n - 1; i++){
        printf(" %d.Div.Diff ", i + 1);
    }
    printf("\n");
    for (i = 0; i < n; i++){
        printf(" %5.1f", X[i]);
        for (j = 0; j < n - i; j++){
            printf("%15f", Y[i][j]);  // Print the differences for each row
        }
        printf("\n");
    }
    
    // Print the polynomial equation based on the divided difference table
    printf("\nP(x)=");
    for (i = 0; i < n; i++){
        printf("(%f)", Y[0][i]);  // Print the coefficient from the divided differences
        for (j = n; j > (n - i); j--){
            printf("(x-(%.0f))", X[n - j]);  // Print the factors (x - xi)
        }
        if (i != (n - 1)) printf("\n +");
    }
    
    // Evaluate the polynomial for the given x value bx
    s = Y[0][0];  // Start with the first term
    for (i = 1; i < n; i++){
        float carp = 1;  // Temporary variable for product calculation
        for (j = 0; j < i; j++){
            carp = carp * (bx - X[j]);  // Compute the product (bx - xi)
        }
        s = s + (carp * Y[0][i]);  // Add the term to the result
    }
    
    // Print the final result
    printf("\n\nResult: P(%f)=%f", bx, s);  // Approximate value of P(bx)
    return 0;  // Exit the program
}

