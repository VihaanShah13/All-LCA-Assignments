#include <stdio.h>

int main() {
    int number, result;

    printf("Enter a number:\n");
    scanf("%d", &number);

    result = number / 10;

    printf("Number after removing the last digit = %d\n", result);

    return 0;
}
