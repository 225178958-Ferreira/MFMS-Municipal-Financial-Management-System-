//Assets managment

#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

typedef struct
{
    int assetID;
    char assetName[100];
    char assetType[50];
    float purchaseValue;
    char department[50];
    char condition[30];
} Asset;

void assetMenu(void);
void addAsset(void);
void displayAssets(void);
void searchAsset(void);
int getAssetCount(void);
Asset *getAssets(void);
void assetSeedData(void);

#endif
