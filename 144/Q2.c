#include <stdio.h>
int main() {
    int matrix[10][10], n, i, j, sum = 0;
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);
    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for(i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    printf("The sum of the left diagonal is: %d\n", sum);
    return 0;
}
