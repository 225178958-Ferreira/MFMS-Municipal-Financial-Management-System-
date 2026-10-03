#include <stdio.h>
#include <string.h>
#include "employees.h"

static Employee employees[MAX_EMPLOYEES];
static int employeeCount = 0;

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

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

void addEmployee(void)
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("Employee storage is full.\n");
        return;
    }

    Employee *e = &employees[employeeCount];

    printf("\n--- Add Employee ---\n");
    do
{
    printf("Employee ID: ");
    scanf("%d", &e->employeeID);
    getchar();

    int duplicate = 0;

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].employeeID == e->employeeID)
        {
            duplicate = 1;
            printf("Employee ID already exists. Please enter a different ID.\n");
            break;
        }
    }

    if (duplicate)
        e->employeeID = -1;

} while (e->employeeID == -1);

    printf("Name: ");
    readLine(e->name, sizeof(e->name));

    printf("Department: ");
    readLine(e->department, sizeof(e->department));

    do {
        printf("Basic Salary: N$ ");
        scanf("%f", &e->basicSalary);
        if (e->basicSalary < 0) printf("Salary cannot be negative.\n");
    } while (e->basicSalary < 0);

    do {
        printf("Housing Allowance: N$ ");
        scanf("%f", &e->housingAllowance);
        if (e->housingAllowance < 0) printf("Allowance cannot be negative.\n");
    } while (e->housingAllowance < 0);

    do {
        printf("Transport Allowance: N$ ");
        scanf("%f", &e->transportAllowance);
        if (e->transportAllowance < 0) printf("Allowance cannot be negative.\n");
    } while (e->transportAllowance < 0);

    getchar();
    employeeCount++;
    printf("\nEmployee added successfully.\n");
}

void displayEmployees(void)
{
    printf("\n================ EMPLOYEE LIST ================\n");

    if (employeeCount == 0)
    {
        printf("No employees registered.\n");
        return;
    }

    for (int i = 0; i < employeeCount; i++)
    {
        Employee *e = &employees[i];
        printf("\nID: %d\n", e->employeeID);
        printf("Name: %s\n", e->name);
        printf("Department: %s\n", e->department);
        printf("Basic Salary: N$%.2f\n", e->basicSalary);
        printf("Housing: N$%.2f\n", e->housingAllowance);
        printf("Transport: N$%.2f\n", e->transportAllowance);
        printf("Total Salary: N$%.2f\n",
               calculateSalary(e->basicSalary, e->housingAllowance, e->transportAllowance));
    }
}

void searchEmployee(void)
{
    int id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].employeeID == id)
        {
            Employee *e = &employees[i];
            printf("\nEmployee found!\n");
            printf("ID: %d\nName: %s\nDepartment: %s\n",
                   e->employeeID, e->name, e->department);
            printf("Total Salary: N$%.2f\n",
                   calculateSalary(e->basicSalary, e->housingAllowance, e->transportAllowance));
            return;
        }
    }

    printf("Employee with ID %d was not found.\n", id);
}

void calculateEmployeeSalary(void)
{
    int id;
    printf("\nEnter Employee ID: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].employeeID == id)
        {
            Employee *e = &employees[i];
            float total = calculateSalary(e->basicSalary, e->housingAllowance, e->transportAllowance);
            printf("\nSalary Calculation\n");
            printf("Basic Salary       : N$%.2f\n", e->basicSalary);
            printf("Housing Allowance  : N$%.2f\n", e->housingAllowance);
            printf("Transport Allowance: N$%.2f\n", e->transportAllowance);
            printf("TOTAL SALARY       : N$%.2f\n", total);
            return;
        }
    }

    printf("Employee not found.\n");
}

void employeeMenu(void)
{
    int choice;
    do
    {
        printf("\n============= EMPLOYEE MANAGEMENT =============\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Salary\n");
        printf("5. Back to Main Menu\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); pauseScreen(); break;
            case 3: searchEmployee(); pauseScreen(); break;
            case 4: calculateEmployeeSalary(); pauseScreen(); break;
            case 5: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);
}

int getEmployeeCount(void) { return employeeCount; }
Employee *getEmployees(void) { return employees; }

void employeeSeedData(void)
{
    employees[0] = (Employee){1001, "Anna Shilongo", "Finance", 18000, 2500, 1500};
    employees[1] = (Employee){1002, "Peter Nangolo", "Engineering", 22000, 3000, 1800};
    employees[2] = (Employee){1003, "Maria Uusiku", "Human Resources", 16500, 2500, 1500};
    employeeCount = 3;
}
