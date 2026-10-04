#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "input.h"

/* =========================================================
 * Employee Management
 * Handles employee creation, display, searching and salary
 * calculations.
 * ========================================================= */

static Employee employees[MAX_EMPLOYEES];
static int employeeCount = 0;

static void readLine(char *text, int size)
{
    if (fgets(text, size, stdin))
        text[strcspn(text, "\n")] = '\0';
}

/* Calculate total employee salary */
float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

/* Add a new employee and check for duplicate employee IDs */
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
        e->employeeID = getInt("Employee ID: ");

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

    e->basicSalary =
        getNonNegativeFloat("Basic Salary: N$ ");

    e->housingAllowance =
        getNonNegativeFloat("Housing Allowance: N$ ");

    e->transportAllowance =
        getNonNegativeFloat("Transport Allowance: N$ ");

    employeeCount++;

    printf("\nEmployee added successfully.\n");
}

/* Display all registered employees and their salary details */
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
               calculateSalary(
                   e->basicSalary,
                   e->housingAllowance,
                   e->transportAllowance));
    }
}

/* Search for an employee using the employee ID */
void searchEmployee(void)
{
    int id = getInt("\nEnter Employee ID to search: ");

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].employeeID == id)
        {
            Employee *e = &employees[i];

            printf("\nEmployee found!\n");
            printf("ID: %d\n", e->employeeID);
            printf("Name: %s\n", e->name);
            printf("Department: %s\n", e->department);
            printf("Total Salary: N$%.2f\n",
                   calculateSalary(
                       e->basicSalary,
                       e->housingAllowance,
                       e->transportAllowance));

            return;
        }
    }

    printf("Employee with ID %d was not found.\n", id);
}

/* Calculate and display an employee's total salary */
void calculateEmployeeSalary(void)
{
    int id = getInt("\nEnter Employee ID: ");

    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].employeeID == id)
        {
            Employee *e = &employees[i];

            float total = calculateSalary(
                e->basicSalary,
                e->housingAllowance,
                e->transportAllowance);

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

int getEmployeeCount(void)
{
    return employeeCount;
}

Employee *getEmployees(void)
{
    return employees;
}

/* Load sample employee data for system testing */
void employeeSeedData(void)
{
    employees[0] = (Employee){
        1001, "Anna Shilongo", "Finance", 18000, 2500, 1500
    };

    employees[1] = (Employee){
        1002, "Peter Nangolo", "Engineering", 22000, 3000, 1800
    };

    employees[2] = (Employee){
        1003, "Maria Uusiku", "Human Resources", 16500, 2500, 1500
    };

    employeeCount = 3;
}

/* Employee management menu and user navigation */
void employeeMenu(void)
{
    int choice;

    do
    {
        printf("\n========== EMPLOYEE MANAGEMENT ==========\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Employee Salary\n");
        printf("5. Back to Main Menu\n");
        printf("=========================================\n");

        choice = getMenuChoice("Enter your choice: ", 1, 5);

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                displayEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                calculateEmployeeSalary();
                break;

            case 5:
                printf("Returning to main menu...\n");
                break;
        }

    } while (choice != 5);
}