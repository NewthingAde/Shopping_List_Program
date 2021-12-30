#define _CRT_SECURE_NO_WARNINGS
#include "ShoppingList.h"
#include <stdio.h>
#include <stdlib.h> // For malloc() and free()
#include <string.h>

void addItem(struct ShoppingList *list)
{
	int noOfItem = 0;
	int product;
	int amount;

	noOfItem = list->length + 1;

	list->itemList = realloc(list->itemList, noOfItem * sizeof(struct GrocaryItem));

	if (list->itemList == NULL)
	{
		printf("\nMemory was not allocated!");
		exit(0);
	}
	else
	{
		// printf("\nMemory was successfully allocatetd!");
		printf("\nEnter name: ");
		scanf("%s", list->itemList[list->length].productName);


		printf("\nEnter amount: ");
		scanf("%f", &list->itemList[list->length].amount);

		while (list->itemList[list->length].amount < 0)
		{
			printf("You can not enter -ve amount.\nEnter +ve amount: ");
			scanf("%f", &list->itemList[list->length].amount);
		}

		printf("\nEnter unit: ");
		scanf("%s", list->itemList[list->length].unit);

		printf("\n%s was added to the shopping list.", list->itemList[list->length].productName);
		// Increase the length
		list->length++;
	}
	// free(list->itemList); // can not use as in next run the pointer will be lost
	//printf("\n length of list: %d", list->length);
}

void printList(struct ShoppingList *list)
{
	int index = 1;
	if (list->length == 0)
	{
		printf("\nYour list is empty.");
	}
	else
	{
		printf("\nYour list contains %d items:\n\n", list->length);

		for (int i = 0; i < list->length; ++i)
		{
			printf("%d.\t%s\t%.2f\t%s\n", index, list->itemList[i].productName, list->itemList[i].amount, list->itemList[i].unit);
			index++;
		}
	}
}

void editItem(struct ShoppingList *list)
{
	int itemOption;
	float newAmount;
	printf("\nWhich item do you want to change? ");
	scanf("%d", &itemOption);
	// Check if the list is empty.
	if (list->length == 0)
	{
		printf("\nYour list is empty");
	}
	// Check invalid option
	else if (itemOption > list->length)
	{
		printf("\nThe list contains only %d items!", list->length);
	}
	else
	{
		printf("\nCurrent amount: %.2f\t %s", list->itemList[itemOption - 1].amount, list->itemList[itemOption - 1].unit);
		printf("\nEnter new amount: ");
		scanf("%f", &newAmount);
		list->itemList[itemOption - 1].amount = newAmount;
		printf("\nItem number %d is updated.", itemOption);
	}
}

void removeItem(struct ShoppingList *list)
{
	int itemToRemove;
	printf("\nYour list contains %d items:\n", list->length);
	printf("\nWhich item do you want to remove? ");
	scanf("%d", &itemToRemove);

	if (list->length == 0)
	{
		printf("\nYour list is empty. You can not remove anything");
	}
	else if (itemToRemove > list->length)
	{
		printf("\nThe list contains only %d items! Please enter correct item number.", list->length);
	}
	else
	{
		for (int i = itemToRemove - 1; i < list->length; ++i)
		{
			strcpy(list->itemList[i].productName, list->itemList[i + 1].productName);
			list->itemList[i].amount = list->itemList[i + 1].amount;
			strcpy(list->itemList[i].unit, list->itemList[i + 1].unit);
		}
		list->length = list->length - 1;
		printf("\nThe item number %d is deleted", itemToRemove);
	}
}

void saveList(struct ShoppingList *list)
{
	char fileName[20];
	int index = 1;
	FILE *fp;

	printf("\nEnter the file name: ");
	scanf("%s", fileName);
	fp = fopen(strcat(fileName, ".txt"), "w");

		fprintf(fp, "SN\tPN\t\tAmt\t\tUnit\n");
		for (int i = 0; i < list->length; ++i)
		{
			fprintf(fp, "%d.\t%s\t%.2f\t%s\n", index, (list->itemList + i)->productName, (list->itemList + i)->amount, (list->itemList + i)->unit);
			index++;
		}
		fclose(fp);

	
		printf("counld not open file");

	// fprintf(fp, "Reached to the end of file\n");
	printf("\n%d items are added to the %s file.", list->length, fileName);
	fclose(fp);
}

void loadList(struct ShoppingList *list)
{
	char fileName[20], line[256];
	float amount;
	int index = 0, i = 0, k = 0, noOfItem;
	FILE *file;
	const char delimeter[] = "\t";
	char *data[4];
	list->length = 0;
	noOfItem = list->length + 1;

	printf("\nEnter the file name: ");
	scanf("%s", fileName);
	file = fopen(strcat(fileName, ".txt"), "r");

	if (file == NULL)
	{
		printf("You have entered a wrong file name. Please eneter a correct file name\n");
	}

	else
	{
		noOfItem = 0;
		// Free the memory for old list
		// free(list->itemList);
		// printf("Currently Loaded list: \n");
		while (fgets(line, sizeof(line), file))
		{
			if (line[0] == index + '0')
			{
				// sscanf(line, fileName,"%[^\n]%*c");
				// printf("printing line[0] %c\n",line[0]);
				// Allocate new memory
				list->itemList = realloc(list->itemList, noOfItem * sizeof(struct GrocaryItem));

				// Find Tab space to break and get the data
				char *tab = strtok(line, delimeter);

				while (tab)
				{
					data[i++] = tab;
					tab = strtok(NULL, delimeter);
					if (line[k] == '\n')
					{
						//printf("\nline break found");
						break;
					}
					k++;
				}

				// Save items in the list item
				strcpy(list->itemList[list->length].productName, data[1]);
				amount = strtof(data[2], NULL);
				list->itemList[list->length].amount = amount;
				strcpy(list->itemList[list->length].unit, data[3]);
				list->length++;
				// printf("\n line one completed and length here is %d\n",list->length);
			}

			noOfItem++;
			i = 0;
			index++;
		}
	}
	// Set list length and deduct first and last line
	list->length = noOfItem - 2;
	// Show items of list loaded
	//printf("%d items are loaded from the shopping list: \n", list->length);
	// free(list->itemList);
	fclose(file);
}
