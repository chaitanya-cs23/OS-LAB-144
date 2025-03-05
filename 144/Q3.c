#include <stdio.h>
int main() {
    int matrix[10][10], rowSum[10] = {0}, colSum[10] = {0};
    int m, n, i, j;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }
    printf("\nSum of each row:\n");
    for(i = 0; i < m; i++) {
        printf("Row %d: %d\n", i + 1, rowSum[i]);
    }


    printf("\nSum of each column:\n");
    for(j = 0; j < n; j++) {
        printf("Column %d: %d\n", j + 1, colSum[j]);
    }

    return 0;
}
