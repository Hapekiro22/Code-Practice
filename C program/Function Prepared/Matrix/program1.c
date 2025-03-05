#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-6

void print_matrix(double *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%g ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

void swap_rows(double *matrix, int row1, int row2, int cols) {
    for (int i = 0; i < cols; i++) {
        double temp = matrix[row1 * cols + i];
        matrix[row1 * cols + i] = matrix[row2 * cols + i];
        matrix[row2 * cols + i] = temp;
    }
}

void gaussian_elimination(double *matrix, int rows, int cols) {
    int i, j, k;
    for (i = 0; i < rows; i++) {
        // Find the pivot row
        int max_row = i;
        for (j = i + 1; j < rows; j++) {
            if (fabs(matrix[j * cols + i]) > fabs(matrix[max_row * cols + i])) {
                max_row = j;
            }
        }

        // Swap the pivot row with the current row
        if (max_row != i) {
            swap_rows(matrix, i, max_row, cols);
        }

        // Make all rows below this one 0 in the current column
        for (j = i + 1; j < rows; j++) {
            double factor = matrix[j * cols + i] / matrix[i * cols + i];
            for (k = i; k < cols; k++) {
                matrix[j * cols + k] -= factor * matrix[i * cols + k];
            }
        }
    }
}

void back_substitution(double *matrix, double *solution, int rows, int cols, double a) {
    for (int i = rows - 1; i >= 0; i--) {
        solution[i] = matrix[i * cols + cols - 1];
        for (int j = i + 1; j < cols - 1; j++) {
            solution[i] -= matrix[i * cols + j] * solution[j];
        }
        solution[i] /= matrix[i * cols + i];
    }
    // Express the solution in terms of parameter a
    for (int i = 0; i < rows; i++) {
        solution[i] *= a;
    }
}

int main() {
    int rows = 4, cols = 5; // 4x4 matrix with an extra column for the augmented matrix
    double matrix[rows * cols];
    double a;

    printf("Enter the elements of the 4x4 matrix row by row:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            scanf("%lf", &matrix[i * cols + j]);
        }
        matrix[i * cols + cols - 1] = 0.0; // Augmented column for homogeneous system
    }

    printf("Enter the parameter a: ");
    scanf("%lf", &a);

    printf("Original matrix:\n");
    print_matrix(matrix, rows, cols);

    gaussian_elimination(matrix, rows, cols);

    printf("\nMatrix after Gaussian elimination:\n");
    print_matrix(matrix, rows, cols);

    double *solution = malloc(rows * sizeof(double));
    back_substitution(matrix, solution, rows, cols, a);

    printf("\nSolution (in terms of parameter a):\n");
    for (int i = 0; i < rows; i++) {
        printf("x%d = %g * a\n", i + 1, solution[i]);
    }

    free(solution);

    return 0;
}