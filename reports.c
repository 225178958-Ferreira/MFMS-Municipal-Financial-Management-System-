#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

/*
 * Displays a message asking the user to press ENTER
 * before continuing back to the Reports menu.
 */
static void pauseScreen(void)
{
    char temp[8];

    printf("\nPress ENTER to continue...");

    /* Read the ENTER key from the user */
    fgets(temp, sizeof(temp), stdin);
}

/*
 * Generates the Employee Report.
 *
 * The report displays:
 * - Total number of employees
 * - Average salary
 * - Highest salary
 * - Lowest salary
 */
void employeeReport(void)
{
    /* Get the employee array from the Employee module */
    Employee *e = getEmployees();

    /* Get the number of employees currently stored */
    int count = getEmployeeCount();

    /* Check if there are no employees to report */
    if (count == 0)
    {
        printf("No employees available.\n");
        return;
    }

    /* Variables used to calculate salary statistics */
    float total = 0, highest = 0, lowest = 0;

    /*
     * Loop through all employees and calculate
     * their total salary.
     */
    for (int i = 0; i < count; i++)
    {
        /*
         * Total salary is calculated using:
         * Basic Salary + Housing Allowance + Transport Allowance
         */
        float salary = e[i].basicSalary + e[i].housingAllowance + e[i].transportAllowance;

        /* Add the employee's salary to the overall total */
        total += salary;

        /*
         * If this is the first employee, or the current
         * salary is greater than the highest salary,
         * update the highest salary.
         */
        if (i == 0 || salary > highest)
            highest = salary;

        /*
         * If this is the first employee, or the current
         * salary is lower than the lowest salary,
         * update the lowest salary.
         */
        if (i == 0 || salary < lowest)
            lowest = salary;
    }

    /* Display the Employee Report */
    printf("\n================ EMPLOYEE REPORT ================\n");
    printf("Total Employees : %d\n", count);

    /* Calculate and display the average salary */
    printf("Average Salary  : N$%.2f\n", total / count);

    /* Display the highest salary found */
    printf("Highest Salary  : N$%.2f\n", highest);

    /* Display the lowest salary found */
    printf("Lowest Salary   : N$%.2f\n", lowest);
}

/*
 * Generates the Budget Report.
 *
 * The report displays:
 * - Total allocated budget
 * - Total expenditure
 * - Remaining budget
 * - Departments that exceeded their budget
 */
void budgetReport(void)
{
    /* Get the budget array from the Budget module */
    Budget *b = getBudgets();

    /* Get the number of budgets currently stored */
    int count = getBudgetCount();

    /* Variables used to calculate budget totals */
    float allocated = 0, expenditure = 0;

    printf("\n================= BUDGET REPORT =================\n");

    /*
     * Loop through all departments and calculate
     * the total allocated budget and expenditure.
     */
    for (int i = 0; i < count; i++)
    {
        /* Add the department's allocated budget */
        allocated += b[i].allocatedBudget;

        /* Add the department's expenditure */
        expenditure += b[i].expenditure;
    }

    /* Display the total allocated budget */
    printf("Total Allocated Budget : N$%.2f\n", allocated);

    /* Display the total expenditure */
    printf("Total Expenditure      : N$%.2f\n", expenditure);

    /*
     * Remaining budget is calculated by subtracting
     * total expenditure from total allocated budget.
     */
    printf("Remaining Budget       : N$%.2f\n", allocated - expenditure);

    printf("\nDepartments exceeding budget:\n");

    /*
     * 'found' is used to determine whether at least
     * one department has exceeded its budget.
     */
    int found = 0;

    /*
     * Check every department to see if its expenditure
     * is greater than its allocated budget.
     */
    for (int i = 0; i < count; i++)
    {
        if (b[i].expenditure > b[i].allocatedBudget)
        {
            /* Display the department that exceeded its budget */
            printf("- %s\n", b[i].department);

            /* Indicate that an over-budget department was found */
            found = 1;
        }
    }

    /*
     * If no department exceeded its budget,
     * display "None".
     */
    if (!found)
        printf("None\n");
}

/*
 * Generates the Supplier Report.
 *
 * The report displays:
 * - Number of registered suppliers
 * - Supplier information
 */
void supplierReport(void)
{
    printf("\n================ SUPPLIER REPORT ================\n");

    /* Display the number of registered suppliers */
    printf("Registered Suppliers: %d\n", getSupplierCount());

    /* Display the details of all registered suppliers */
    displaySuppliers();
}

/*
 * Generates the Asset Report.
 *
 * The report displays:
 * - Number of registered assets
 * - Total value of all assets
 * - Asset information
 */
void assetReport(void)
{
    /* Get the asset array from the Asset module */
    Asset *a = getAssets();

    /* Get the number of registered assets */
    int count = getAssetCount();

    /* Variable used to calculate the total asset value */
    float total = 0;

    printf("\n================== ASSET REPORT ==================\n");

    /* Display the number of registered assets */
    printf("Registered Assets: %d\n", count);

    /*
     * Loop through all assets and add their
     * purchase values together.
     */
    for (int i = 0; i < count; i++)
        total += a[i].purchaseValue;

    /* Display the combined value of all assets */
    printf("Total Asset Value: N$%.2f\n", total);

    /* Display the details of all registered assets */
    displayAssets();
}

/*
 * Displays the Reports menu.
 *
 * The user can choose which report to generate
 * or return to the Main Menu.
 */
void reportsMenu(void)
{
    int choice;

    /* Keep displaying the menu until the user chooses option 5 */
    do
    {
        printf("\n==================== REPORTS ====================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");

        /* Read the user's menu choice */
        scanf("%d", &choice);

        /*
         * Remove the newline character left in the
         * input buffer by scanf().
         */
        getchar();

        /* Perform an action based on the selected option */
        switch (choice)
        {
            /* Generate the Employee Report */
            case 1:
                employeeReport();
                pauseScreen();
                break;

            /* Generate the Budget Report */
            case 2:
                budgetReport();
                pauseScreen();
                break;

            /* Generate the Supplier Report */
            case 3:
                supplierReport();
                pauseScreen();
                break;

            /* Generate the Asset Report */
            case 4:
                assetReport();
                pauseScreen();
                break;

            /* Return to the Main Menu */
            case 5:
                break;

            /* Handle an invalid menu choice */
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);
}

/*
 * Loads the initial sample data for the system.
 *
 * Each module has its own seed-data function.
 * This function calls all of them when the program starts.
 */
void loadSampleData()
{
    /* Load sample employee records */
    employeeSeedData();

    /* Load sample budget records */
    budgetSeedData();

    /* Load sample supplier records */
    supplierSeedData();

    /* Load sample asset records */
    assetSeedData();
}