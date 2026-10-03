#include <stdio.h>
#include <string.h>
#include "assets.h"

static Asset assets[MAX_ASSETS];
static int assetCount = 0;

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

void addAsset(void)
{
    if (assetCount >= MAX_ASSETS)
    {
        printf("Asset storage is full.\n");
        return;
    }

    Asset *a = &assets[assetCount];

    printf("\nAsset ID: ");
    scanf("%d", &a->assetID);
    getchar();

    printf("Asset Name: ");
    readLine(a->assetName, sizeof(a->assetName));
    printf("Asset Type: ");
    readLine(a->assetType, sizeof(a->assetType));

    do {
        printf("Purchase Value: N$ ");
        scanf("%f", &a->purchaseValue);
        if (a->purchaseValue < 0) printf("Value cannot be negative.\n");
    } while (a->purchaseValue < 0);
    getchar();

    printf("Department: ");
    readLine(a->department, sizeof(a->department));
    printf("Condition: ");
    readLine(a->condition, sizeof(a->condition));

    assetCount++;
    printf("Asset added successfully.\n");
}

void displayAssets(void)
{
    printf("\n================ ASSET REGISTER ================\n");

    for (int i = 0; i < assetCount; i++)
    {
        printf("\nID: %d\nName: %s\nType: %s\nPurchase Value: N$%.2f\nDepartment: %s\nCondition: %s\n",
               assets[i].assetID, assets[i].assetName, assets[i].assetType,
               assets[i].purchaseValue, assets[i].department, assets[i].condition);
    }
}

void searchAsset(void)
{
    int id;
    printf("\nEnter Asset ID to search: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < assetCount; i++)
    {
        if (assets[i].assetID == id)
        {
            printf("\nAsset found!\n");
            printf("ID: %d\nName: %s\nType: %s\nValue: N$%.2f\nDepartment: %s\nCondition: %s\n",
                   assets[i].assetID, assets[i].assetName, assets[i].assetType,
                   assets[i].purchaseValue, assets[i].department, assets[i].condition);
            return;
        }
    }

    printf("Asset not found.\n");
}

void assetMenu(void)
{
    int choice;
    do
    {
        printf("\n============== ASSET MANAGEMENT ==============\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1: addAsset(); break;
            case 2: displayAssets(); pauseScreen(); break;
            case 3: searchAsset(); pauseScreen(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}

int getAssetCount(void) { return assetCount; }
Asset *getAssets(void) { return assets; }

void assetSeedData(void)
{
    assets[0] = (Asset){3001, "Toyota Hilux", "Vehicle", 450000, "Engineering", "Good"};
    assets[1] = (Asset){3002, "Dell Desktop PC", "Computer", 18000, "Finance", "Excellent"};
    assets[2] = (Asset){3003, "Office Building", "Building", 2500000, "Administration", "Good"};
    assetCount = 3;
}
