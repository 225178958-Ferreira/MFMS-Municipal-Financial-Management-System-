#ifndef SUPPLIERS_H
#define SUPPLIERS_H
/* Maximum num of suppliers */
#define MAX_SUPPLIERS 100

/* Used stores one supplier each */
typedef struct
{
    int supplierID;
    char name[100];
    char email[100];
    char telephone[30];
    char location[50];
} Supplier;

/* Shows the supplier menu */
void supplierMenu(void);

/* Adds a new supplier */
void addSupplier(void);

/* Displays all suppliers */
void displaySuppliers(void);

/* Searches for a supplier by name */
void searchSupplier(void);

/* Returns how many suppliers stored */
int getSupplierCount(void);

/* Returns the suppliers array for the other modules */
Supplier *getSuppliers(void);

/* Loads sample suppliers */
void supplierSeedData(void);

#endif
