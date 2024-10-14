#include <stdio.h>

#define SIZE 5

void print(int matrix[SIZE][SIZE], int rows, int cols) { //Initialize print function. Take in matrix and the number of rows and columns
    for (int i = 0; i < rows; i++) { //Iterate i over indeces 0 to the number of rows-1.
        printf("\n"); //Newline after each row.
        for (int j = 0; j < cols; j++) { //Iterate j over indeces 0 to the number of columns-1
            printf("%d ", matrix[i][j]); //Print the value of the matrix at row i column j.
        }
    }
}
void add(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) { //Initialize the add function. Take in two matrices, and create a result matrix.
    for (int i = 0; i < SIZE; i++) { //Iterate i to the SIZE value.
        for (int j = 0; j < SIZE; j++) { //Iterate j to the SIZE value.
            result[i][j] = a[i][j] + b[i][j]; //Set the result matrix at (i,j) to the value of matrix a and b at (i,j) added together.
        }
    }
}
void multiply(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) { //Initialize the multiply function. Take in two matrices and create the result matrix.
    for (int i = 0; i < SIZE; i++) { //Iterate i from index 0 to SIZE-1.
        for (int j = 0; j < SIZE; j++) { //Iterate j from index 0 to SIZE-1.
            result[i][j] = 0; //Set the value of the result matrix at (i,j) to 0.
            for (int k = 0; k < SIZE; k++) { //Lines 23-25. Iterate k from index 0 to SIZE-1. k is an important variable to follow the rules of matrix multiplication. ie. Multiply the (i,k) of a to (k,j) of b and add it to the result matrix at (i,j).
                result[i][j] += a[i][k] * b[k][j]; 
            }
        }
    }
}
void transpose(int matrix[SIZE][SIZE], int transposed[SIZE][SIZE]) { //Initialize transpose function. 
    for (int i = 0; i < SIZE; i++) { //Iterate i from index 0 to SIZE-1.
        for (int j = 0; j < SIZE; j++) { //Iterate j from index 0 to SIZE-1.
            transposed[j][i] = matrix[i][j]; //Transposing a matrix is simply flipping over the main diagonal. Thus, we simply set the result matrix to the inverse coordinates of the original matrix. ie. (i,j) of the matrix is transposed to (j,i)
        }
    }
}
int main() { //Initialize main function.
    int m1[SIZE][SIZE] = { //Create the given m1 matrix.
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = { //Create the given m2 matrix.
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    int sum[SIZE][SIZE]; //Lines 51-54. Initialize all the output matrices.
    int product[SIZE][SIZE];
    int transpose1[SIZE][SIZE];
    int transpose2[SIZE][SIZE]; 
    add(m1, m2, sum); //Call the add function with m1 and m2 as inputs with our sum matrix as the result.
    multiply(m1, m2, product); //Call the multiply function with m1 and m2 as inputs with our product matrix as the result.
    transpose(m1, transpose1); //Call the transpose function for m1.
    transpose(m2, transpose2); //Call the transpose function for m2.
    printf("Matrix m1:\n"); //Print that we are showing matrix 1.
    print(m1, SIZE, SIZE); //Call the print matrix function for m1.
    printf("\nMatrix m2:\n"); //Print we are showing matrix 2.
    print(m2, SIZE, SIZE); //Call the print matrix function for m2.
    printf("\nSum of m1 and m2:\n"); //Print that we are showing the sum of m1 and m2.
    print(sum, SIZE, SIZE); //Call the print matrix function with the sum matrix as the input so we continue to use a nice format for the user.
    printf("\nProduct of m1 and m2:\n");
    print(product, SIZE, SIZE); //Call the print matrix function with the product matrix as the input so we continue to use a nice format for the user.
    printf("\nTranspose of m1:\n"); //Print that we are showing the transpose of m1.
    print(transpose1, SIZE, SIZE); //Call the print matrix function with the transpose1 matrix as the input so we continue to use a nice format for the user.
    printf("\nTranspose of m2:\n"); //Print that we are showing the transpose of m2.
    print(transpose2, SIZE, SIZE); //Call the print matrix function with the transpose2 matrix as the input so we continue to use a nice format for the user.
    return 0;
}