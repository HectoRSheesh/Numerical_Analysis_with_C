#include <stdio.h>
#include <math.h>

// Function to calculate the actual value of cos(x)
float f(float a){
    return cos(a);  // Returns the cosine of a given angle (in radians)
}

int main(void){
    
    double toplam, y, x;  // Variables for the result, intermediate value, and converted angle
    int i, n, k, is, c, j, aci;  // Loop variables and angle input
    
    // Prompt the user to enter the degree of the polynomial
    printf("Enter the degree of the polynomial: ");
    scanf("%u", &n);
    
    // Prompt the user to enter the angle (in degrees)
    printf("Enter the angle to approximate its value: ");
    scanf("%d", &aci);
    
    // Convert the angle from degrees to radians
    x = aci * M_PI / 180;
    toplam = 1;  // Initialize the sum for the Taylor series
    is = -1;  // Alternating sign (-1 for odd terms)
    
    // Loop to calculate the Taylor series approximation
    for (i = 2; i <= n; i += 2){
        c = 1;  // Initialize the factorial
        for (j = 1; j <= i; j++){
            c *= j;  // Compute the factorial of i
        }
        // Calculate the term in the series
        y = (pow(x, i) / c) * is;  // (x^i / i!) * alternating sign
        toplam += y;  // Add the term to the total sum
        is = is * (-1);  // Alternate the sign for the next term
    }
    
    // Output the approximation, actual value, and error
    printf("Approximate value: cos(%d)=%f \n", aci, toplam);
    printf("Actual value: cos(%d)=%f \n", aci, f(x));
    printf("Error=%f \n", fabs(toplam - f(x)));  // Calculate the absolute error
    
    return 0;  // Exit the program
}

