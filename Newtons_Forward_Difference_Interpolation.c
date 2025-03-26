#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
int fakt(int a){
    int i, faktoriyel = 1;
    for (i = 1; i <= a; i++)
        faktoriyel = faktoriyel * i;  // Multiply successive integers to calculate factorial
    return faktoriyel;
}

int main(void){
    
    int m, n, i, j;  // Variables for loop counters and number of points
    printf("Enter the number of points ---> ");
    scanf("%d", &n);
    
    // Declare arrays for x and y values and other necessary variables
    float X[n], Y[n][n], s, bx, h;
    printf("Enter the x value for which you want to find the approximate result ---> ");
    scanf("%f", &bx);
    
    // Input the x and y values of the points
    for (i = 0; i < n; i++){
        printf("Enter the x value for point %d: ", i + 1);
        scanf("%f", &X[i]);
        printf("Enter the y value for point %d: ", i + 1);
        scanf("%f", &Y[i][0]);
    }
    
    // Calculate the forward difference table
    for (i = 1; i < n; i++){
        for (j = 0; j < n - i; j++){
            Y[j][i] = (Y[j + 1][i - 1] - Y[j][i - 1]);  // Compute the differences
        }
    }
    
    // Print the forward difference table
    printf("\nForward Difference Table\n");
    printf(" xi yi=f(xi)");
    
    for (i = 0; i < n - 1; i++){
        printf(" %d.Forward Diff.", i + 1);}
    printf("\n");
    for (i = 0; i < n; i++){
        printf(" %5.1f", X[i]);
        for (j = 0; j < n - i; j++){
            printf("%15f", Y[i][j]);  // Print the differences for each row
        }
        printf("\n");
    }
    
    // Calculate the step size h
    h = X[1] - X[0];
    
    // Print the polynomial equation
    printf("\nP(x)=(%f)\n +", Y[0][0]);
    for (i = 1; i < n; i++){
        printf("((%f)/((%d) * (%f)))*", Y[0][i], fakt(i), pow(h, i));
        for (j = n; j > (n - i); j--){
            printf("(x-(%.1f))", X[n - j]);  // Print the factors of (x - xi)
        }
        if (i != (n - 1)) printf("\n +");
    }
    
    // Evaluate the polynomial for the given x value bx
    s = Y[0][0];
    h = X[1] - X[0];
    
    for (i = 1; i < n; i++){
        float carp = 1;  // Temporary variable for product calculation
        for (j = 0; j < i; j++){
            carp = carp * (bx - X[j]);  // Compute (bx - xi) for all points
        }
        s = s + (carp * (Y[0][i] / (pow(h, i) * fakt(i))));  // Add the term to the result
    }
    
    // Print the final result
    printf("\n\nResult: P(%.2f)=%f", bx, s);
    return 0;  // Exit the program
}

