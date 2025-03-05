#include <stdio.h>
int main() {
    int arr[100], n, i, j, count = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) {
       int foundDuplicate = 0;
        for(j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                foundDuplicate = 1;
                break;
            }
        }
        if (!foundDuplicate) {
            for(j = i + 1; j < n; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                    break;
                }
            }
        }
    }
    printf("Total number of duplicate elements: %d\n", count);

    return 0;
}
