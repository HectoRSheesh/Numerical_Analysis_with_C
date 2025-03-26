//
//  Fixed_Point_Theorem.c
//
//
//  Created by Ozan Bali on 26.03.2025.
//

#include<stdio.h>
#include<math.h>
#define miss 0.002  // Define the error tolerance for approximation

// Function to calculate the next approximation value
float F(float x){
    return (pow(x,3)+1)/2;  // Fixed-point function
}

int main(void){
    
    float x1=0.5,x2;  // Initial value x1 and variable x2 for previous value
    int i=0;  // Counter to keep track of the number of iterations
    printf("Starting point of the method= %.4f\n",x1);

    do{
        x2=x1;          // Store current approximation value
        x1=F(x1);       // Calculate the next approximation value
        i++;            // Increment the iteration counter
        printf("Approximation value at step %d= %.4f\n",i,x1);
    }while ( fabs(x1-x2) > miss ); // Repeat until the error tolerance is satisfied

    printf("Approximate root =%.4f\n",x1);  // Print the final approximate root
    printf("f(%.4f)=%.4f\n",x1,pow(x1,3)-2*x1+1);  // Print the value of the function at the approximate root
}
