#include <stdio.h>
#include <string.h>

struct sensor
{
    int id;
    char type[15];
    float dist;
    float threshold;
    char status[25];
    char risk[15];
};

int main()
{
    struct sensor s[50];

    int n, i;
    int high = 0, medium = 0, low = 0;
    int minIndex = 0;

    printf("\n===== ROBOT SENSOR SYSTEM =====\n");

    printf("Enter number of sensors: ");
    scanf("%d", &n);

    if (n <= 0 || n > 50)
    {
        printf("Invalid number of sensors!");
        return 1;
    }

    // Input sensor details
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for Sensor %d:\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &s[i].id);

        printf("Enter Type: ");
        scanf("%14s", s[i].type);

        printf("Enter Distance (cm): ");
        scanf("%f", &s[i].dist);

        printf("Enter Threshold (cm): ");
        scanf("%f", &s[i].threshold);

        if (s[i].dist < 0 || s[i].threshold <= 0)
        {
            printf("Invalid Reading!\n");
            return 1;
        }
    }

    // Determine status and risk level
    for (i = 0; i < n; i++)
    {
        // Determine obstacle status
        if (s[i].dist <= s[i].threshold)
        {
            strcpy(s[i].status, "Obstacle Detected");
        }
        else
        {
            strcpy(s[i].status, "Path Clear");
        }

        // Classify risk level
        if (s[i].dist <= s[i].threshold)
        {
            strcpy(s[i].risk, "High Risk");
            high++;
        }
        else if (s[i].dist <= s[i].threshold * 1.5)
        {
            strcpy(s[i].risk, "Medium Risk");
            medium++;
        }
        else
        {
            strcpy(s[i].risk, "Low Risk");
            low++;
        }

        // Find nearest obstacle (minimum distance)
        if (s[i].dist < s[minIndex].dist)
        {
            minIndex = i;
        }
    }

    // Display sensor details
    printf("\n========== SENSOR DETAILS ==========\n");

    printf("%-8s %-12s %-12s %-12s %-20s %-12s\n",
           "ID", "Type", "Distance", "Threshold", "Status", "Risk");

    printf("--------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%-8d %-12s %-12.2f %-12.2f %-20s %-12s\n",
               s[i].id,
               s[i].type,
               s[i].dist,
               s[i].threshold,
               s[i].status,
               s[i].risk);
    }

    // Display risk counts
    printf("\n========== SUMMARY ==========\n");

    printf("High Risk Sensors   : %d\n", high);
    printf("Medium Risk Sensors : %d\n", medium);
    printf("Low Risk Sensors    : %d\n", low);

    // Display nearest obstacle
    printf("\nNearest Obstacle:\n");
    printf("Sensor ID : %d\n", s[minIndex].id);
    printf("Distance  : %.2f cm\n", s[minIndex].dist);

    return 0;
}
