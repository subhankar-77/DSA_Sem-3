#include <stdio.h>
int main()
{
    int r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    int mat[r][c];
    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("The input matrix is:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("Sparse Matrix Representation \n(row, col, value):\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(mat[i][j] != 0) {
                printf("(%d, %d, %d)\n", i, j, mat[i][j]);
            }
        }
    }
    return 0;
}
