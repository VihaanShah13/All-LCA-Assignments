#include <stdio.h>

int main() {
    int arr[100], n, i;
    int smallest, secondSmallest, found = 0;

    printf("Enter the number of elements (2-100):\n");
    scanf("%d", &n);

    if (n < 2 || n > 100) {
        printf("Invalid number of elements");
        return 0;
    }

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    smallest = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
            found = 1;
        } else if (arr[i] > smallest && (found == 0 || arr[i] < secondSmallest)) {
            secondSmallest = arr[i];
            found = 1;
        }
    }

    if (found == 1) {
        printf("Second smallest element: %d\n", secondSmallest);
    } else {
        printf("No distinct second-smallest element found.\n");
    }

    return 0;
}
