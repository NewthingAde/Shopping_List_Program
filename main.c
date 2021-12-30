#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "ShoppingList.h"

int main(void)
{
	struct ShoppingList shoppingList;
	shoppingList.length = 0; // The shopping list is empty at the start
	shoppingList.itemList = NULL;
	int option;

	do
	{
		printf("\n\nWelcome to the shopping list manager!\n");
		printf("=====================================\n\n");

		printf("1. Add an item\n");
		printf("2. Display the shopping list\n");
		printf("3. Remove an item\n");
		printf("4. Change an item\n");
		printf("5. Save list\n");
		printf("6. Load list\n");
		printf("7. Exit\n");

		printf("What do you want to do? ");
		scanf("%d", &option);

		switch (option)
		{
		case 1: addItem(&shoppingList); break;
		case 2: printList(&shoppingList); break;
		case 3: removeItem(&shoppingList); break;
		case 4: editItem(&shoppingList); break;
		case 5: saveList(&shoppingList); break;
		case 6: loadList(&shoppingList); break;
		case 7: break;
		default:
			printf("Please enter a number between 1 and 7");
		}
	} while (option != 7);

	return 0;
}

