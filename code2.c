//Trey Baptista eecs 348 lab 5
#include <stdio.h> 

#define size 5 
  
// Function to add two matrices 
void addMatrices(int m1[size][size], int m2[size][size], int result[size][size]) { 
    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size; j++) {  // Changed from `i++` to `j++` 
            result[i][j] = m1[i][j] + m2[i][j]; 
        } 
    } 
} 
  
// Function to multiply two matrices 
void multiplyMatrices(int m1[size][size], int m2[size][size], int result[size][size]) { 

    // Initialize result matrix to 0 
    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size; j++) { 
            result[i][j] = 0; 
        } 
    } 
  
    // Multiply m1 and m2, store in result 
    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size; j++) { 
            for (int k = 0; k < size; k++) { 
                result[i][j] += m1[i][k] * m2[k][j]; 
            } 
        } 
    } 
} 
  
// Function to calculate the transpose of a matrix 
void transposeMatrix(int matrix[size][size], int result[size][size]) { 
    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size; j++) { 
            result[j][i] = matrix[i][j];  // Assign transpose to result 
        } 
    } 
} 
  
//print a matrix 
void printMatrix(int matrix[size][size]) { 
    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size; j++) { 
            printf("%4d ", matrix[i][j]); 
        } 
        printf("\n"); 
    } 
} 

  

int main() { 

    int m1[size][size] = { 

        {1, 2, 3, 4, 5}, 

        {6, 7, 8, 9, 10}, 

        {11, 12, 13, 14, 15}, 

        {16, 17, 18, 19, 20}, 

        {21, 22, 23, 24, 25} 

    }; 

  

    int m2[size][size] = { 

        {25, 24, 23, 22, 21}, 

        {20, 19, 18, 17, 16}, 

        {15, 14, 13, 12, 11}, 

        {10, 9, 8, 7, 6}, 

        {5, 4, 3, 2, 1} 

    }; 

  

    int sum[size][size]; 

    int product[size][size]; 

    int transpose[size][size]; 

  

    // Calculate and print the sum of m1 and m2 

    printf("Sum of m1 and m2:\n"); 

    addMatrices(m1, m2, sum); 

    printMatrix(sum); 

  

    // Calculate and print the product of m1 and m2 

    printf("\nProduct of m1 and m2:\n"); 

    multiplyMatrices(m1, m2, product); 

    printMatrix(product); 

    // Calculate and print the transpose of m1 

    printf("\nTranspose of m1:\n"); 

    transposeMatrix(m1, transpose); 

    printMatrix(transpose); 

    return 0; 

} 

 
