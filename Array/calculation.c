#include <stdio.h>

#define MAX_SIZE 10

void add_matrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multiply_matrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int res[MAX_SIZE][MAX_SIZE], int row1, int col1, int col2)
{

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < col1; k++)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transpose_matrix(int mat[MAX_SIZE][MAX_SIZE], int trans[MAX_SIZE][MAX_SIZE], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            trans[j][i] = mat[i][j];
        }
    }
}

void display_matrix(int mat[MAX_SIZE][MAX_SIZE], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, row, col;
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE], transpose[MAX_SIZE][MAX_SIZE];

    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d %d", &row, &col);

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Add Matrices\n");
        printf("2. Multiply Matrices\n");
        printf("3. Transpose Matrix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_matrices(mat1, mat2, result, row, col);
            printf("Result of addition:\n");
            display_matrix(result, row, col);
            break;
        case 2:
            multiply_matrices(mat1, mat2, result, row, col, col);
            printf("Result of multiplication:\n");
            display_matrix(result, row, col);
            break;
        case 3:
            transpose_matrix(mat1, transpose, row, col);
            printf("Transpose of the first matrix:\n");
            display_matrix(transpose, col, row);
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
