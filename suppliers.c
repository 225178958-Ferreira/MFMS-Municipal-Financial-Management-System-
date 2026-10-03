#include <stdio.h>
#include <string.h>
#include "suppliers.h"

/* All suppliers (static = private to this file) */
static Supplier suppliers[MAX_SUPPLIERS];

/* Number of suppliers stored (also the next free slot) */
static int supplierCount = 0;

/*
*Reads a line of text
*fgets() keeps the '\n', which breaks strcmp(), so strcspn() can find and relplace it 
*/
static void readLine(char *text, int size)
{
    if (fgets(text, size, stdin))
        text[strcspn(text, "\n")] = '\0';
}

/* Waits for ENTER before returning to the menu */
static void pauseScreen(void)
{
    char temp[8];
    printf("\nPress ENTER to continue...");
    fgets(temp, sizeof(temp), stdin);
}

/*  to Add a supplier, check space, fill the next free slot, then count it */
void addSupplier(void)
{
     /* Stops if the array is full */
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier storage is full.\n");
        return;
    }
    
    /* Next free slot */
    Supplier *s = &suppliers[supplierCount];

    printf("\nSupplier ID: ");
    scanf("%d", &s->supplierID);
    
     /* Removes the '\n' left by scanf() so  fgets() is not skipped */
    getchar();
    
    /* used to stops text going past the end of the array (sizeof())  */
    printf("Supplier Name: ");
    readLine(s->name, sizeof(s->name));
    printf("Email: ");
    readLine(s->email, sizeof(s->email));
    printf("Telephone: ");
    readLine(s->telephone, sizeof(s->telephone));
    printf("Town/Location: ");
    readLine(s->location, sizeof(s->location));

    supplierCount++;
    printf("Supplier added successfully.\n");
}

/* Displays all suppliers */
void displaySuppliers(void)
{
    printf("\n================ SUPPLIERS ================\n");
    
  /* Array From the first supplier  to the last (supplierCount - 1) */
    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nID: %d\nName: %s\nEmail: %s\nTelephone: %s\nLocation: %s\n",
               suppliers[i].supplierID, suppliers[i].name, suppliers[i].email,
               suppliers[i].telephone, suppliers[i].location);
    }
}

/* Searches for a supplier by exact name */

void searchSupplier(void)
{
    /* *
    *strcmp() returns 0 when the text is equal 
    *(never use == for strings) 
    */
    char name[100];

    printf("\nEnter supplier name to search: ");
    readLine(name, sizeof(name));

    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(suppliers[i].name, name) == 0)
        {
            printf("\nSupplier found!\n");
            printf("ID: %d\nName: %s\nEmail: %s\nTelephone: %s\nLocation: %s\n",
                   suppliers[i].supplierID, suppliers[i].name, suppliers[i].email,
                   suppliers[i].telephone, suppliers[i].location);
            return;
        }
    }
    
     /* Nothing is found */
    printf("Supplier not found.\n");
}

 /* Supplier menu: repeats until the user chooses 4 (Back) */
void supplierMenu(void)
{
    int choice;
    
    /* do-while and switch */
    do
    {
        printf("\n============= SUPPLIER MANAGEMENT =============\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: addSupplier(); break;
            case 2: displaySuppliers(); pauseScreen(); break;
            case 3: searchSupplier(); pauseScreen(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}

int getSupplierCount(void) { return supplierCount; }
Supplier *getSuppliers(void) { return suppliers; }

/* Loads 2 sample suppliers */
void supplierSeedData(void)
{
    suppliers[0] = (Supplier){2001, "ABC Office Supplies", "abc@example.com", "0812345678", "Windhoek"};
    suppliers[1] = (Supplier){2002, "NamTech Solutions", "info@namtech.com", "0855551234", "Ongwediva"};
    supplierCount = 2;
}
