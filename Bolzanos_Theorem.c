//
//  main.c
//  Bolzanos_Theorem
//
//  Created by Ozan Bali on 26.03.2025.
//

#include <stdio.h>
#include <math.h>

// Define the function F(x)
float F(float x){
    return pow(x, 3) + pow(x, 2) - 1;  // Returns x^3 + x^2 - 1
}

int main(void){
    float a; // Starting value for the interval
    float b; // Ending value for the interval

    printf("Enter the value of a: ");  // Prompt user to input starting value
    scanf ("%f" ,&a);
    printf("Enter the value of b: ");  // Prompt user to input ending value
    scanf ("%f",&b);
           
    // Check if the product of F(a) and F(b) is negative
    if ((F(a) * F(b)) < 0){
        // Bolzano's theorem ensures there's at least one root in the interval
        printf("According to Bolzano's theorem, there is at least one root between %.2f and %.2f...", a, b);
    } else {
        // Bolzano's theorem conditions are not satisfied
        printf("The conditions for Bolzano's theorem are not met, so nothing definitive can be said about the existence of a root...");
    }
}
