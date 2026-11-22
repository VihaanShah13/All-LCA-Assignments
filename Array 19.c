#include <stdio.h>

int main() {
    int arr[100], n, i;
    int largest, secondLargest, found = 0;

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

    largest = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
            found = 1;
        } else if (arr[i] < largest && (found == 0 || arr[i] > secondLargest)) {
            secondLargest = arr[i];
            found = 1;
        }
    }

    if (found == 1) {
        printf("Second largest element: %d\n", secondLargest);
    } else {
        printf("No distinct second-largest element found.\n");
    }

    return 0;
}
