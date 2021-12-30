#ifndef SHOPPING_LIST_H
#define SHOPPING_LIST_H


// Struct definitions

struct GrocaryItem
{
	char productName[20];
	float amount;
	char unit[10];
};

struct ShoppingList
{
	int length;
	struct GrocaryItem *itemList;
};

// Function declarations

void addItem(struct ShoppingList *list);
void printList(struct ShoppingList *list);
void editItem(struct ShoppingList *list);
void removeItem(struct ShoppingList *list);
void saveList(struct ShoppingList *list);
void loadList(struct ShoppingList* list);

#endif
