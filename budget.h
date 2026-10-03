#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 50

typedef struct
{
    char department[50];
    float allocatedBudget;
    float expenditure;
} Budget;

void budgetMenu(void);
void addBudget(void);
void displayBudgets(void);
void budgetSummary(void);
int getBudgetCount(void);
Budget *getBudgets(void);
void budgetSeedData(void);

#endif
