/*
2d map

(C)2024 Tim Jacobs

for efficient storage of 16bit integers
in matrix form
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
typedef of the matrix with the
data about these
*/
typedef struct
{
    int rows;
    int cols;
    int16_t** data;
} Matrix;

/*
function that returns a matrix struct
the memory is allocated in this function
but no value is assigned
*/
Matrix initMatrix(int rows, int cols)
{
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    
    /*
    allocate the memory row for row with the size
    of an integer
    */
    mat.data = \
        (int**)malloc(rows * sizeof(int16_t*));
    if (mat.data == NULL)
    {
        printf("ERROR allocate");
        exit(1);
    }
    
    /*
    allocate the memory column for column with
    the size of an integer
    */
    for (int i = 0; i < rows; i++) 
    {
        mat.data[i] = \
            (int*)malloc(cols * sizeof(int16_t));
        if (mat.data[i] == NULL)
        {
            printf("ERROR allocate");
            exit(1);
        }
    }
    
    return mat;
}

/*
function to deallocate the full matrix
*/
void freeMatrix(Matrix* mat) 
{
    
    /*
    deallocate row for row
    */
    for (int i = 0; i < mat->rows; i++) 
    {
        free(mat->data[i]);
    }

    free(mat->data);
    free(mat->rows);
    free(mat->cols);
}

/*
    testmodul only for testing under development
*/
int main() 
{
    // Initialisierung einer Matrix
    Matrix matrix = initMatrix(3334, 2345);

    int16_t testnum = matrix.data[2][6];
    printf("%d", testnum);
    
    // Freigabe des allokierten Speichers
    freeMatrix(&matrix);
    
    printf("ok main");

    return 0;
}
