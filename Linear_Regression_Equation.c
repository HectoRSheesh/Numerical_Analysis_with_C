#include <stdio.h>
#include <stdlib.h>

// Function to calculate the determinant of a 2x2 matrix
float determinant(float M[2][2]);

// Function to print a 2x2 matrix
void matrisyaz(float N[2][2]);

int main(void){
    
    int m, n, i, j, t, s, topx = 0, topy = 0, topx2 = 0, topyx = 0, detA;

    // Prompt the user to enter the number of data points
    printf("Enter the number of points ---> ");
    scanf("%d", &n);

    // Declare arrays to store x and y values, and matrices for calculations
    float X[n], Y[n], A[2][2], B[2], tempA[2][2], c[2];

    // Input the x and y values for each point
    for (i = 0; i < n; i++){
        printf("Enter the x value for point %d: ", i + 1);
        scanf("%f", &X[i]);
        printf("Enter the y value for point %d: ", i + 1);
        scanf("%f", &Y[i]);
    }

    // Compute sums needed for the regression calculations
    for (i = 0; i < n; i++){
        topx = topx + X[i];  // Sum of x values
        topy = topy + Y[i];  // Sum of y values
        topx2 = topx2 + (X[i] * X[i]);  // Sum of x^2 values
        topyx = topyx + (X[i] * Y[i]);  // Sum of x*y values
    }

    // Initialize the coefficient matrix (A) and result matrix (B)
    A[0][0] = n; A[0][1] = topx;
    A[1][0] = topx; A[1][1] = topx2;
    B[0] = topy; B[1] = topyx;

    // Print information about the linear system
    printf("The linear equation system has been solved using Cramer's Rule...\n");
    printf("Coefficient matrix:");
    matrisyaz(A);

    printf("B result matrix:\n");

    for (i = 0; i < 2; i++)
        printf("%f\n", B[i]);

    printf("\n");

    // Calculate the determinant of the coefficient matrix
    detA = determinant(A);

    // Solve the system using Cramer's Rule
    for (i = 0; i < 2; i++){
        // Copy the original matrix into a temporary matrix
        for (t = 0; t < 2; t++){
            for (s = 0; s < 2; s++){
                tempA[t][s] = A[t][s];
            }
        }

        // Replace the i-th column with the B matrix
        for (j = 0; j < 2; j++){
            tempA[j][i] = B[j];
        }

        // Calculate the solution for the i-th variable
        c[i] = determinant(tempA) / detA;
        printf("%d. column replaced with elements of B matrix:", i + 1);
        matrisyaz(tempA);
    }

    // Print the results
    printf("Results:\n");
    for (i = 0; i < 2; i++){
        printf("c[%d] = %f\n", i + 1, c[i]);
    }

    // Print the derived linear regression equation
    printf("\nDerived First-Degree Linear Regression Equation (Line Equation):\n");
    printf("y = %f + (%f).x\n", c[0], c[1]);

    return 0;
}

// Function to calculate the determinant of a 2x2 matrix
float determinant(float M[2][2]){
    float det;
    det = (M[0][0] * M[1][1]) - (M[0][1] * M[1][0]);  // Calculate determinant
    return det;
}

// Function to print a 2x2 matrix
void matrisyaz(float N[2][2]){
    int i, j;
    for (i = 0; i < 2; i++){
        printf("\n");
        for (j = 0; j < 2; j++)
            printf("%.3f\t", N[i][j]);  // Print each element
    }
    printf("\n");
}

