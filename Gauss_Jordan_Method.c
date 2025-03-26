#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define BOYUT 3  // Define the size of the matrix (3x3)

// Function to print a matrix
void matrisyaz(float N[BOYUT][BOYUT+1]);

int main(void){
    
    float A[BOYUT][BOYUT+1], f;  // Augmented matrix (A) and factor (f)
    int i, j, k;  // Loop variables
    
    // Initialize the augmented matrix (A)
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3; A[0][3] = 9;
    A[1][0] = 2; A[1][1] = -1; A[1][2] = 1; A[1][3] = 8;
    A[2][0] = 3; A[2][1] = 0; A[2][2] = -1; A[2][3] = 3;
    
    // Print the augmented matrix (before elimination)
    printf("Augmented Coefficient Matrix:");
    matrisyaz(A);
    printf("\n\n");
    
    // Reduce the augmented matrix to Echelon Form (forward elimination)
    for (k = 0; k < BOYUT - 1; k++)  // Loop through rows
        for (i = k + 1; i < BOYUT; i++){  // Loop through remaining rows
            f = A[i][k] / A[k][k];  // Calculate the factor for elimination
            for (j = k; j < BOYUT + 1; j++){
                A[i][j] = A[i][j] - f * A[k][j];  // Eliminate current element
            }
        }
    
    // Print the augmented matrix after forward elimination
    printf("Augmented Coefficient Matrix in Echelon Form:");
    matrisyaz(A);
    printf("\n");
    
    // Scale the leading coefficients to 1
    for (i = 0; i < BOYUT; i++){  // Loop through rows
        for (j = 0; j < BOYUT; j++){  // Loop through columns
            if (i == j) {  // Ensure it's a diagonal element
                f = 1 / A[i][j];  // Scale factor
                for (k = 0; k < BOYUT + 1; k++)  // Scale the entire row
                    A[i][k] = A[i][k] * f;
            }
        }
    }
    
    matrisyaz(A);
    printf("\n");
    printf("Augmented Coefficient Matrix with Leading Coefficients as 1:");
    
    // Convert the augmented matrix to Reduced Row Echelon Form (back substitution)
    for (k = BOYUT - 1; k > 0; k--)  // Loop from last row to first
        for (i = k - 1; i >= 0; i--){  // Loop backwards through rows
            f = A[i][k] / A[k][k];  // Elimination factor
            for (j = 0; j < BOYUT + 1; j++){
                A[i][j] = A[i][j] - f * A[k][j];  // Eliminate current element
            }
        }
    
    // Print the matrix in reduced row echelon form
    matrisyaz(A);
    printf("\n");
    printf("Augmented Coefficient Matrix in Reduced Row Echelon Form:");
    
    // Print the final solutions
    printf("Solutions: \n");
    for (i = 0; i < BOYUT; i++){
        printf("X[%d] = %f\n", i + 1, A[i][BOYUT]);
    }
    
    return(0);  // Exit the program
} // End of main function
    
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

