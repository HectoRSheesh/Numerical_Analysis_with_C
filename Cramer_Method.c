#include <stdio.h>

// Function declarations
float determinant(float M[3][3]);  // Function to calculate the determinant of a 3x3 matrix
void matrisyaz(float N[3][3]);    // Function to print a 3x3 matrix

int main(void){
    // Variable declarations
    float A[3][3], B[3],           // Coefficient matrix A and result matrix B
          tempA[3][3], detA, x[3]; // Temporary matrix, determinant of A, and solution vector
    int i, j, t, s;                // Loop variables
    
    // Initialize the coefficient matrix (A) and result matrix (B)
    A[0][0] = 2; A[0][1] = -1; A[0][2] = -1; B[0] = 2;
    A[1][0] = 4; A[1][1] = 1;  A[1][2] = -1; B[1] = -5;
    A[2][0] = 6; A[2][1] = -2; A[2][2] = 2;  B[2] = 17;
    
    // Print the coefficient matrix (A)
    printf("Coefficient matrix:");
    matrisyaz(A);
    
    // Print the result matrix (B)
    printf("B result matrix:\n");
    for(i = 0; i < 3; i++)
        printf("%.3f\n", B[i]);
    printf("\n");

    // Calculate the determinant of the coefficient matrix (A)
    detA = determinant(A);
    
    // Loop through each column of matrix A
    for(i = 0; i < 3; i++){
        // Copy matrix A into a temporary matrix
        for(t = 0; t < 3; t++){
            for(s = 0; s < 3; s++){
                tempA[t][s] = A[t][s];
            }
        }
        // Replace the i-th column of tempA with the result matrix (B)
        for(j = 0; j < 3; j++){
            tempA[j][i] = B[j];
        }
        
        // Calculate the determinant of the modified matrix and solve for x[i]
        x[i] = determinant(tempA) / detA;
        
        // Print the modified matrix after replacing the i-th column
        printf("%d. column elements replaced with B matrix elements:", i + 1);
        matrisyaz(tempA);
    }
    
    // Print the solution vector (x)
    printf("Results:\n");
    for(i = 0; i < 3; i++)
        printf("x[%d] = %.3f\n", i + 1, x[i]);
    
    return 0;  // Exit the program
}

// Function to calculate the determinant of a 3x3 matrix
float determinant(float M[3][3]){
    float det, m1, m2, m3;

    // Calculate the determinant using the cofactor expansion
    m1 = M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1]);
    m2 = M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0]);
    m3 = M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]);
    det = m1 + (-1) * m2 + m3;  // Calculate determinant
    return det;
}

// Function to print a 3x3 matrix
void matrisyaz(float N[3][3]){
    int i, j;
    for(i = 0; i < 3; i++){
        printf("\n");
        for(j = 0; j < 3; j++)
            printf("%.3f\t", N[i][j]);  // Print each element in the matrix
    }
    printf("\n\n");
}

