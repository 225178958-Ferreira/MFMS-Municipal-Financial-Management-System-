#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

static void clearInput(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static int getMenuChoice(int min, int max)
{
    int choice;
    while (1)
    {
        printf("Enter your choice: ");
        if (scanf("%d", &choice) == 1 && choice >= min && choice <= max)
        {
            clearInput();
            return choice;
        }

        printf("Invalid choice. Please enter a number from %d to %d.\n", min, max);
        clearInput();
    }
}

int main(void)
{
    int choice;

    loadSampleData();

    do
    {
        printf("\n===============================================\n");
        printf("     MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("===============================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");
        printf("===============================================\n");

        choice = getMenuChoice(1, 6);

        switch (choice)
        {
            case 1: employeeMenu(); break;
            case 2: budgetMenu(); break;
            case 3: supplierMenu(); break;
            case 4: assetMenu(); break;
            case 5: reportsMenu(); break;
            case 6:
                printf("\nThank you for using the Municipal Financial Management System.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
