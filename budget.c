
#include <stdio.h>
#include <string.h>
#include "budget.h"

/* Static internal storage for budget records and current item count */
static Budget budgets[MAX_BUDGETS];
static int budgetCount = 0;

/**
 * Reads a line of input safely from stdin and removes the trailing newline.
 * @param text Buffer to store the input string
 * @param size Maximum capacity of the buffer
 */
static void readLine(char *text, int size)
{
    if (fgets(text, size, stdin))
        text[strcspn(text, "\n")] = '\0'; /* Locate and strip newline character */
}

/**
 * Halts execution until the user hits the ENTER key.
 */
static void pauseScreen(void)
{
    char temp[8];
    printf("\nPress ENTER to continue...");
    fgets(temp, sizeof(temp), stdin);
}

/**
 * Prompts user for department details and appends a new budget entry.
 */
void addBudget(void)
{
    /* Check if maximum budget capacity has been reached */
    if (budgetCount >= MAX_BUDGETS)
    {
        printf("Budget storage is full.\n");
        return;
    }

    Budget *b = &budgets[budgetCount]; /* Pointer to the next available slot */

    /* Input department name */
    printf("\nDepartment: ");
    readLine(b->department, sizeof(b->department));

    /* Input and validate allocated budget (must be non-negative) */
    do {
        printf("Allocated Budget: N$ ");
        scanf("%f", &b->allocatedBudget);
        if (b->allocatedBudget < 0) printf("Budget cannot be negative.\n");
    } while (b->allocatedBudget < 0);

    /* Input and validate expenditure (must be non-negative) */
    do {
        printf("Expenditure: N$ ");
        scanf("%f", &b->expenditure);
        if (b->expenditure < 0) printf("Expenditure cannot be negative.\n");
    } while (b->expenditure < 0);

    getchar(); /* Consume remaining newline character from scanf */
    budgetCount++; /* Increment record count */
    printf("Budget added successfully.\n");
}

/**
 * Displays detailed information for each department budget stored.
 */
void displayBudgets(void)
{
    printf("\n================ BUDGET REPORT ================\n");

    /* Iterate over all added budget records */
    for (int i = 0; i < budgetCount; i++)
    {
        float remaining = budgets[i].allocatedBudget - budgets[i].expenditure;

        printf("\nDepartment: %s\n", budgets[i].department);
        printf("Allocated : N$%.2f\n", budgets[i].allocatedBudget);
        printf("Expenditure: N$%.2f\n", budgets[i].expenditure);
        printf("Remaining : N$%.2f\n", remaining);
        /* Check if remaining balance is within limit or over budget */
        printf("Status    : %s\n", remaining >= 0 ? "WITHIN BUDGET" : "OVER BUDGET");
    }
}

/**
 * Generates summary statistics across all departments and lists over-budget items.
 */
void budgetSummary(void)
{
    float totalAllocated = 0, totalExpenditure = 0;

    /* Aggregate totals across all budget records */
    for (int i = 0; i < budgetCount; i++)
    {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
    }

    printf("\nTotal Allocated : N$%.2f\n", totalAllocated);
    printf("Total Expenditure: N$%.2f\n", totalExpenditure);
    printf("Remaining Budget: N$%.2f\n", totalAllocated - totalExpenditure);

    /* Filter and list departments exceeding their budget */
    printf("\nDepartments exceeding budget:\n");
    int found = 0;
    for (int i = 0; i < budgetCount; i++)
    {
        if (budgets[i].expenditure > budgets[i].allocatedBudget)
        {
            printf("- %s\n", budgets[i].department);
            found = 1;
        }
    }
    if (!found) printf("None\n");
}

/**
 * Interactive menu loop providing options for managing department budgets.
 */
void budgetMenu(void)
{
    int choice;
    do
    {
        printf("\n============== BUDGET MANAGEMENT ==============\n");
        printf("1. Add Department Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Budget Summary\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); /* Clear newline character left in input buffer */

        switch (choice)
        {
            case 1: addBudget(); break;
            case 2: displayBudgets(); pauseScreen(); break;
            case 3: budgetSummary(); pauseScreen(); break;
            case 4: break; /* Exit menu loop */
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}

/* Returns the total number of active budget entries */
int getBudgetCount(void) { return budgetCount; }

/* Returns a pointer to the array of budget records */
Budget *getBudgets(void) { return budgets; }

/**
 * Populates default sample data into the array for testing and demonstration.
 */
void budgetSeedData(void)
{
    /* Seed Finance Department */
    strcpy(budgets[0].department, "Finance");
    budgets[0].allocatedBudget = 500000;
    budgets[0].expenditure = 420000;

    /* Seed Engineering Department */
    strcpy(budgets[1].department, "Engineering");
    budgets[1].allocatedBudget = 800000;
    budgets[1].expenditure = 850000;

    /* Seed Human Resources Department */
    strcpy(budgets[2].department, "Human Resources");
    budgets[2].allocatedBudget = 350000;
    budgets[2].expenditure = 300000;

    budgetCount = 3; /* Set initial array size count */
}
