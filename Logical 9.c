#include <stdio.h>

int main() {
    int number, first, last, sum;

    printf("Enter a non-negative number:\n");
    scanf("%d", &number);

    if (number < 0) {
        printf("Please enter a non-negative number.");
        return 0;
    }

    first = number;
    while (first >= 10) {
        first = first / 10;
    }

    last = number % 10;
    sum = first + last;

    printf("Sum of first and last digit = %d\n", sum);

    return 0;
}
