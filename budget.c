#include <stdio.h>
#include <string.h>
#include "budget.h"

static Budget budgets[MAX_BUDGETS];
static int budgetCount = 0;

static void readLine(char *text, int size)
{
    if (fgets(text, size, stdin))
        text[strcspn(text, "\n")] = '\0';
}

static void pauseScreen(void)
{
    char temp[8];
    printf("\nPress ENTER to continue...");
    fgets(temp, sizeof(temp), stdin);
}

void addBudget(void)
{
    if (budgetCount >= MAX_BUDGETS)
    {
        printf("Budget storage is full.\n");
        return;
    }

    Budget *b = &budgets[budgetCount];

    printf("\nDepartment: ");
    readLine(b->department, sizeof(b->department));

    do {
        printf("Allocated Budget: N$ ");
        scanf("%f", &b->allocatedBudget);
        if (b->allocatedBudget < 0) printf("Budget cannot be negative.\n");
    } while (b->allocatedBudget < 0);

    do {
        printf("Expenditure: N$ ");
        scanf("%f", &b->expenditure);
        if (b->expenditure < 0) printf("Expenditure cannot be negative.\n");
    } while (b->expenditure < 0);

    getchar();
    budgetCount++;
    printf("Budget added successfully.\n");
}

void displayBudgets(void)
{
    printf("\n================ BUDGET REPORT ================\n");

    for (int i = 0; i < budgetCount; i++)
    {
        float remaining = budgets[i].allocatedBudget - budgets[i].expenditure;

        printf("\nDepartment: %s\n", budgets[i].department);
        printf("Allocated : N$%.2f\n", budgets[i].allocatedBudget);
        printf("Expenditure: N$%.2f\n", budgets[i].expenditure);
        printf("Remaining : N$%.2f\n", remaining);
        printf("Status    : %s\n", remaining >= 0 ? "WITHIN BUDGET" : "OVER BUDGET");
    }
}

void budgetSummary(void)
{
    float totalAllocated = 0, totalExpenditure = 0;

    for (int i = 0; i < budgetCount; i++)
    {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
    }

    printf("\nTotal Allocated : N$%.2f\n", totalAllocated);
    printf("Total Expenditure: N$%.2f\n", totalExpenditure);
    printf("Remaining Budget: N$%.2f\n", totalAllocated - totalExpenditure);

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
        getchar();

        switch (choice)
        {
            case 1: addBudget(); break;
            case 2: displayBudgets(); pauseScreen(); break;
            case 3: budgetSummary(); pauseScreen(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}

int getBudgetCount(void) { return budgetCount; }
Budget *getBudgets(void) { return budgets; }

void budgetSeedData(void)
{
    strcpy(budgets[0].department, "Finance");
    budgets[0].allocatedBudget = 500000;
    budgets[0].expenditure = 420000;

    strcpy(budgets[1].department, "Engineering");
    budgets[1].allocatedBudget = 800000;
    budgets[1].expenditure = 850000;

    strcpy(budgets[2].department, "Human Resources");
    budgets[2].allocatedBudget = 350000;
    budgets[2].expenditure = 300000;

    budgetCount = 3;
}
