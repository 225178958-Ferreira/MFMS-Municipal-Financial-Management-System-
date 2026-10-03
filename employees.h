#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

typedef struct
{
    int employeeID;
    char name[100];
    char department[50];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
} Employee;

void employeeMenu(void);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateEmployeeSalary(void);
int getEmployeeCount(void);
Employee *getEmployees(void);
void employeeSeedData(void);

#endif