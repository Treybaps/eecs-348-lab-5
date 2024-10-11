//Trey Baptista lab 5

#include <stdio.h>

#define months 12

int main() {
    // Month names
    const char * monthNames[months] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    // Array for sales
    double sales[months];

    // Open the file
    FILE *file = fopen("sales.txt", "r");
    if (!file) {
        printf("Error: unable to open file.\n");
        return 1;
    }

    // Read sales data from the file
    for (int i = 0; i < months; i++) {
        fscanf(file, "%lf", &sales[i]); // Correct format specifier
    }
    fclose(file);

    // Monthly sales report
    printf("Monthly Sales Report for 2024\n");
    printf("Month       Sales\n");
    for (int i = 0; i < months; i++) {
        printf("%-12s $%.2f\n", monthNames[i], sales[i]); // Align output
    }

    // Sales summary report
    double min = sales[0], max = sales[0], sum = 0.0;
    int minIndex = 0, maxIndex = 0;

    for (int i = 0; i < months; i++) {
        sum += sales[i];
        if (sales[i] < min) {
            min = sales[i];
            minIndex = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxIndex = i;
        }
    }

    double avg = sum / months;
    printf("\nSales Summary Report:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, monthNames[minIndex]);
    printf("Maximum sales: $%.2f (%s)\n", max, monthNames[maxIndex]);
    printf("Average sales: $%.2f\n", avg);

    // Six-month moving average report
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= months - 6; i++) {
        double movingSum = 0.0;
        for (int j = i; j < i + 6; j++) {
            movingSum += sales[j];
        }
        double movingAvg = movingSum / 6.0;
        printf("%s - %s: $%.2f\n", monthNames[i], monthNames[i + 5], movingAvg);
    }

    // Sales report (highest to lowest)
    double sortedSales[months];
    const char *sortedMonths[months];

    for (int i = 0; i < months; i++) {
        sortedSales[i] = sales[i];
        sortedMonths[i] = monthNames[i];
    }

    // Sort sales and corresponding months
    for (int i = 0; i < months - 1; i++) {
        for (int j = i + 1; j < months; j++) {
            if (sortedSales[i] < sortedSales[j]) {
                // Swap sales
                double tempSales = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = tempSales;

                // Swap corresponding months
                const char *tempMonth = sortedMonths[i];
                sortedMonths[i] = sortedMonths[j];
                sortedMonths[j] = tempMonth;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month       Sales\n");
    for (int i = 0; i < months; i++) {
        printf("%-12s $%.2f\n", sortedMonths[i], sortedSales[i]); // Align output
    }

    return 0;
}
