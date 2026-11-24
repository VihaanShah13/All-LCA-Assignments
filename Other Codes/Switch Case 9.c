#include <stdio.h>

int main() {
    int choice;
    float radius, length, breadth, side, area;

    printf("Select shape to calculate area (1-3)\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Square\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the radius of the circle:\n");
            scanf("%f", &radius);
            area = 3.14 * radius * radius;
            printf("Area of Circle = %.2f\n", area);
            break;

        case 2:
            printf("Enter the length and breadth of the rectangle:\n");
            scanf("%f %f", &length, &breadth);
            area = length * breadth;
            printf("Area of Rectangle = %.2f\n", area);
            break;

        case 3:
            printf("Enter the side of the square:\n");
            scanf("%f", &side);
            area = side * side;
            printf("Area of Square = %.2f\n", area);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
