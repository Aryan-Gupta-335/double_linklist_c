# double_linklist_c
This is a C program that implements a doubly linked list with the following operations:

1. Create a doubly linked list
2. Display the list
3. Insert a node at the beginning
4. Insert a node at the end
5. Insert a node before a given node
6. Delete the first node
7. Delete the last node
8. Delete a node after a given node
9. Exit

The program uses a struct node to represent a node in the list, with an int data field, a next pointer, and a prev pointer for the previous node. It uses a global pointer start to keep track of the starting node of the list.

The program presents a menu-driven interface for the user to interact with the list. Each operation is implemented in a separate function:

- create: Creates a new doubly linked list by repeatedly asking for values until -1 is entered.
- display: Prints the values in the list.
- insertbeg: Inserts a new node at the beginning of the list.
- insertend: Inserts a new node at the end of the list.
- insertbefore: Inserts a new node before a given node.
- deletebeg: Deletes the first node in the list.
- deleteend: Deletes the last node in the list.
- deleteafter: Deletes a node after a given node.

Note that this program has some issues, such as:

- Memory leaks: The program does not free the memory allocated for nodes when they are deleted.
- Lack of error handling: The program does not check for errors when allocating memory or reading input.
- Inconsistent comments: Some comments are outdated or incorrect.

This program can be enhanced by adding more features, such as:

- Inserting nodes at specific positions
- Deleting nodes by value
- Reversing the list
- Sorting the list

Overall, this program demonstrates basic doubly linked list operations in C.
