#include <stdio.h>
#include <string.h>
#include "suppliers.h"

static Supplier suppliers[MAX_SUPPLIERS];
static int supplierCount = 0;

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

void addSupplier(void)
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier storage is full.\n");
        return;
    }

    Supplier *s = &suppliers[supplierCount];

    printf("\nSupplier ID: ");
    scanf("%d", &s->supplierID);
    getchar();

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

void displaySuppliers(void)
{
    printf("\n================ SUPPLIERS ================\n");

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nID: %d\nName: %s\nEmail: %s\nTelephone: %s\nLocation: %s\n",
               suppliers[i].supplierID, suppliers[i].name, suppliers[i].email,
               suppliers[i].telephone, suppliers[i].location);
    }
}

void searchSupplier(void)
{
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

    printf("Supplier not found.\n");
}

void supplierMenu(void)
{
    int choice;
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

void supplierSeedData(void)
{
    suppliers[0] = (Supplier){2001, "ABC Office Supplies", "abc@example.com", "0812345678", "Windhoek"};
    suppliers[1] = (Supplier){2002, "NamTech Solutions", "info@namtech.com", "0855551234", "Ongwediva"};
    supplierCount = 2;
}
