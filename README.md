## Shopping_List_Program

This program lets the user maintain, edit, save and load shopping lists. The program is controlled via a menu of options.

Below are a couple of example runs so that you can get an impression of how the finished program is supposed to work.

# Example run (user input in bold ):

Welcome to the shopping list manager
....................................

Add an item
Print an item
Remove an item
Change an item
Save list
Load list
Exit

What do you want to do? 1

Enter name: Potatoes
Enter amount: 1.5
Enter unit: kg

Potatoes was added to the shopping list.

Welcome to the shopping list manager
....................................

Add an item
Display the shopping list
Remove an item
Change an item
Save list
Load list
Exit
What do you want to do? 1

Enter name: Milk
Enter amount: 2
Enter unit: liter

Milk was added to the shopping list.

Welcome to the shopping list manager
....................................

Add an item
Display the shopping list
Remove an item
Change an item
Save list
Load list
Exit
What do you want to do? 2

Your list contains 2 items:

Potatoes 1.5 kg
Milk 2 liters
Add an item
Display the shopping list
Remove an item
Change an item
Save list
Load list
Exit
What do you want to do? 7

Goodbye!


# ShoppingList.h

This file consists of struct definitions and function declarations for the functions that is implemented. It also contains two data types: one for a grocery item ( struct GroceryItem ) and one for a shopping list ( struct ShoppingList ). 

The GroceryItem struct contains three members: the name of the item (as a string), the amount of the item (as a float ) and finally a string representing which unit the amount is measured in (eg, “kg”, “liter” etc). The unit is represented as a string.

The ShoppingList struct has two members: an array of grocery items and the current length of the shopping list.


# main.c

This file contains the main () -function and the menu that operates the program. 


# addItem ()
This function add an item to the grocery list. 

The function (and all other functions) receives a pointer to a shopping list. This is a pointer to the shopping list defined in main () , and the functions make changes directly to the shopping list that the argument list is pointing to.
The function should ask the user for a name, amount and unit of an item (see the example run above). It then place it last in the shopping list. 

If the user enters a non-positive number for amount, the program tell the user that the input is invalid and repeat the question until a correct answer has been given.



# printList ()
This function print the entire shopping list vertically aligned to the screen. Each item is numbered, starting from 1 (note however, that the first element will still be stored at index 0 in the array, as usual).


If the list is empty (ie, if the length member is zero), the text “the list is empty” is printed instead of a list.

# editItem ()
The user can make changes the amount of a specific item by first prompting the user to enter a number indicating which item to change, and then asking for a new amount.


# removeItem ()
The user can choose an item from the list and remove it. This is done by removing an item by shifting all the content above the removed element one step to the left, overwriting the previous item. For example, if it is the item on index 2 that is removed, the item on index 3 is moved to index 2, etc.

# saveList ()
When the user chooses to save a shopping list, the user should first select a file name. 

# loadList ()
The user is first asked for a file name. If the file does not exist, the program print an error message.

When loading a new shopping list, it will overwrite the previous list that the user was working with. New memory is allocated for the loaded list.

