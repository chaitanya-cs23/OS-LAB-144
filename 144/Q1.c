#include <stdio.h>

int main() {
    int n, i, first, second;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    first = second = 2147483647;

    for(i = 0; i < n; i++) {
        if(arr[i] < first) {
            second = first;
            first = arr[i];
        } else if(arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }

    if(second == 2147483647)
        printf("No second smallest element.\n");
    else
        printf("The second smallest element is %d\n", second);

    return 0;
}
