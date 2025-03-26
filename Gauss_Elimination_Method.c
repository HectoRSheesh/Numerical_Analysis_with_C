#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define BOYUT 3  // Define the size of the matrix (3x3)

// Function to print a matrix
void matrisyaz(float N[BOYUT][BOYUT+1]);

int main(void){
    // Variable declarations
    float A[BOYUT][BOYUT+1], X[BOYUT], f, t;  // Augmented matrix A, solution vector X, and temporary variables
    int i, j, k, n;  // Loop variables and the number of unknowns
    
    // Input the number of unknowns
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);
    
    // Initialize the augmented matrix (A)
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3; A[0][3] = 9;
    A[1][0] = 2; A[1][1] = -1; A[1][2] = 1; A[1][3] = 8;
    A[2][0] = 3; A[2][1] = 0; A[2][2] = -1; A[2][3] = 3;
    
    // Print the augmented matrix (before elimination)
    printf("Augmented Coefficient Matrix:");
    matrisyaz(A);
    printf("\n\n");
    
    // Perform forward elimination to convert the matrix to upper triangular form
    for (k = 0; k < n - 1; k++)
        for (i = k + 1; i < n; i++){
            f = A[i][k] / A[k][k];  // Calculate the factor for elimination
            for (j = k; j < n + 1; j++){
                A[i][j] = A[i][j] - f * A[k][j];  // Eliminate the current row element
            }
        }
    
    // Print the augmented matrix in echelon form (after forward elimination)
    printf("Augmented Coefficient Matrix in Echelon Form:");
    matrisyaz(A);
    
    printf("\n");
    
    // Perform back substitution to find the solutions
    X[n - 1] = A[n - 1][n] / A[n - 1][n - 1];  // Calculate the last variable
    for (i = n - 2; i >= 0; i--){
        t = 0;
        for (j = i + 1; j < n; j++){
            t += A[i][j] * X[j];  // Sum of known variables
        }
        X[i] = (A[i][n] - t) / A[i][i];  // Calculate the current variable
    }
    
    // Print the solutions
    printf("Solutions: \n");
    for (i = 0; i < n; i++){
        printf("X[%d] = %f\n", i + 1, X[i]);
    }
    
    return(0);  // Exit the program
}

// Function to print a matrix
void matrisyaz(float N[BOYUT][BOYUT+1]){
    int i, j;
    {
    for (i = 0; i < BOYUT; i++)
        printf("\n");

    for (j = 0; j < BOYUT + 1; j++)
        printf("%.3f\t", N[i][j]);  // Print each element of the matrix
}
printf("\n");
}

