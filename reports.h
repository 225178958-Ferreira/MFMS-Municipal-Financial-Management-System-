#ifndef REPORTS_H
#define REPORTS_H

/*
 * Displays the Reports menu and allows the user
 * to select a report.
 */
void reportsMenu(void);

/*
 * Generates a report containing employee information,
 * including total employees and salary statistics.
 */
void employeeReport(void);

/*
 * Generates a report containing municipal budget
 * information and identifies departments over budget.
 */
void budgetReport(void);

/*
 * Generates a report displaying all registered
 * suppliers in the system.
 */
void supplierReport(void);

/*
 * Generates a report displaying all registered
 * municipal assets and their total value.
 */
void assetReport(void);

/*
 * Loads the initial sample data for all system modules.
 */
void loadSampleData(void);

/*
 * Loads sample employee records into the employee module.
 */
void employeeSeedData();

/*
 * Loads sample budget records into the budget module.
 */
void budgetSeedData();

/*
 * Loads sample supplier records into the supplier module.
 */
void supplierSeedData();

/*
 * Loads sample asset records into the asset module.
 */
void assetSeedData();

#endif