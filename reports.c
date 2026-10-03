#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

static void pauseScreen(void)
{
    char temp[8];
    printf("\nPress ENTER to continue...");
    fgets(temp, sizeof(temp), stdin);
}

void employeeReport(void)
{
    Employee *e = getEmployees();
    int count = getEmployeeCount();

    if (count == 0)
    {
        printf("No employees available.\n");
        return;
    }

    float total = 0, highest = 0, lowest = 0;

    for (int i = 0; i < count; i++)
    {
        float salary = e[i].basicSalary + e[i].housingAllowance + e[i].transportAllowance;
        total += salary;

        if (i == 0 || salary > highest) highest = salary;
        if (i == 0 || salary < lowest) lowest = salary;
    }

    printf("\n================ EMPLOYEE REPORT ================\n");
    printf("Total Employees : %d\n", count);
    printf("Average Salary  : N$%.2f\n", total / count);
    printf("Highest Salary  : N$%.2f\n", highest);
    printf("Lowest Salary   : N$%.2f\n", lowest);
}

void budgetReport(void)
{
    Budget *b = getBudgets();
    int count = getBudgetCount();
    float allocated = 0, expenditure = 0;

    printf("\n================= BUDGET REPORT =================\n");

    for (int i = 0; i < count; i++)
    {
        allocated += b[i].allocatedBudget;
        expenditure += b[i].expenditure;
    }

    printf("Total Allocated Budget : N$%.2f\n", allocated);
    printf("Total Expenditure      : N$%.2f\n", expenditure);
    printf("Remaining Budget       : N$%.2f\n", allocated - expenditure);

    printf("\nDepartments exceeding budget:\n");
    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (b[i].expenditure > b[i].allocatedBudget)
        {
            printf("- %s\n", b[i].department);
            found = 1;
        }
    }
    if (!found) printf("None\n");
}

void supplierReport(void)
{
    printf("\n================ SUPPLIER REPORT ================\n");
    printf("Registered Suppliers: %d\n", getSupplierCount());
    displaySuppliers();
}

void assetReport(void)
{
    Asset *a = getAssets();
    int count = getAssetCount();
    float total = 0;

    printf("\n================== ASSET REPORT ==================\n");
    printf("Registered Assets: %d\n", count);

    for (int i = 0; i < count; i++)
        total += a[i].purchaseValue;

    printf("Total Asset Value: N$%.2f\n", total);
    displayAssets();
}

void reportsMenu(void)
{
    int choice;

    do
    {
        printf("\n==================== REPORTS ====================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: employeeReport(); pauseScreen(); break;
            case 2: budgetReport(); pauseScreen(); break;
            case 3: supplierReport(); pauseScreen(); break;
            case 4: assetReport(); pauseScreen(); break;
            case 5: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
}

void loadSampleData()
{
    employeeSeedData();
    budgetSeedData();
    supplierSeedData();
    assetSeedData();
}
