#include<stdio.h>
#include<math.h>
#define hata 0.0001  // Define the tolerance for approximation (error)

// Function to calculate the new value of x1
float f1(float a, float b, float c){
    return (30 - (2 * b + 3 * c)) / 8;  // Update formula for x1
}

// Function to calculate the new value of x2
float f2(float a, float b, float c){
    return (1 - (a + 2 * c)) / -9;  // Update formula for x2
}

// Function to calculate the new value of x3
float f3(float a, float b, float c){
    return (31 - (2 * a + 3 * b)) / 6;  // Update formula for x3
}

int main(void){
    // Initial guesses for x1, x2, and x3
    float x1 = 0, x2 = 0, x3 = 0, temp1, temp2, temp3;
    int i = 0;  // Counter for iterations

    // Print the starting point of the method
    printf("Starting point of the method= (%.4f, %.4f, %.4f)\n", x1, x2, x3);
    
    do{
        // Store the current values of x1, x2, and x3 temporarily
        temp1 = x1;
        temp2 = x2;
        temp3 = x3;
        
        // Update x1, x2, and x3 using their respective update functions
        x1 = f1(temp1, temp2, temp3);
        x2 = f2(x1, temp2, temp3);  // Use the updated x1
        x3 = f3(x1, x2, temp3);  // Use the updated x1 and x2
        
        i++;  // Increment the iteration counter

        // Print the approximate values at each step
        printf("%d. step approximate values= (%.4f, %.4f, %.4f)\n", i, x1, x2, x3);
    }while ((fabs(x1 - temp1) > hata) || (fabs(x2 - temp2) > hata) || (fabs(x3 - temp3) > hata));  // Continue until the changes are within tolerance
    
    // Print the final approximate root values
    printf("Approximate root x1=%.4f\n", x1);
    printf("Approximate root x2=%.4f\n", x2);
    printf("Approximate root x3=%.4f\n", x3);

    return 0;  // Exit the program
}

