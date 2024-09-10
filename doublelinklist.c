#include <stdio.h>
#include <stdlib.h>

// Modified structure for doubly linked list node
struct node {
    int data;
    struct node *next;
    struct node *prev; // New field for previous pointer
};

struct node *start = NULL;

// Create a doubly linked list
struct node *create(struct node *start) {
    struct node *newnode, *ptr;
    int num;
    printf("Enter -1 to end\n");
    printf("Enter data\n");
    scanf("%d", &num);
    
    while (num != -1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = NULL;
        newnode->prev = NULL; // Initialize the previous pointer
        
        if (start == NULL) {
            start = newnode;
        } else {
            ptr = start;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->prev = ptr; // Update the previous pointer
        }

        printf("Enter data\n");
        scanf("%d", &num);
    }
    return start;
}

// Display the list
struct node *display(struct node *start) {
    struct node *ptr;
    ptr = start;
    while (ptr != NULL) {
        printf("\t%d\n", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

// Insert at the beginning
struct node *insertbeg(struct node *start) {
    struct node *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    new_node->prev = NULL; // New node previous pointer should be NULL
    
    if (start != NULL) {
        start->prev = new_node; // Update the previous start's previous pointer
    }
    
    start = new_node;
    return start;
}

// Insert at the end
struct node *insertend(struct node *start) {
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    
    if (start == NULL) {
        new_node->prev = NULL; // Initialize previous pointer if list is empty
        start = new_node;
    } else {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
        new_node->prev = ptr; // Update the previous pointer
    }
    return start;
}

// Insert before a given node
struct node *insertbefore(struct node *start) {
    struct node *new_node, *ptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    
    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }
    
    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }
    
    if (ptr == NULL) {
        printf("Value not found in the list\n");
    } else {
        new_node->next = ptr;
        new_node->prev = ptr->prev;
        
        if (ptr->prev != NULL) {
            ptr->prev->next = new_node;
        } else {
            start = new_node;
        }
        
        ptr->prev = new_node;
    }
    return start;
}

// Delete at the beginning
struct node *deletebeg(struct node *start) {
    struct node *ptr;
    
    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }
    
    ptr = start;
    start = start->next;
    
    if (start != NULL) {
        start->prev = NULL; // Update the new start's previous pointer
    }
    
    free(ptr);
    return start;
}

// Delete at the end
struct node *deleteend(struct node *start) {
    struct node *ptr;
    
    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }
    
    ptr = start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    
    if (ptr->prev != NULL) {
        ptr->prev->next = NULL;
    } else {
        start = NULL; // If the list had only one element
    }
    
    free(ptr);
    return start;
}

// Delete after a given node
struct node *deleteafter(struct node *start) {
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the value after which the node has to be deleted : ");
    scanf("%d", &val);
    
    if (start == NULL) {
        printf("List is empty\n");
        return start;
    }
    
    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }
    
    if (ptr == NULL || ptr->next == NULL) {
        printf("No such element to delete\n");
    } else {
        temp = ptr->next;
        ptr->next = temp->next;
        
        if (temp->next != NULL) {
            temp->next->prev = ptr;
        }
        
        free(temp);
    }
    return start;
}

int main() {
    int ch;
    do {
        printf("\n MENU\n");
        printf("1:create\n");
        printf("2:display\n");
        printf("3:insert at beg\n");
        printf("4:insert at end\n");
        printf("5:insert before\n");
        printf("6:delete first\n");
        printf("7:delete last\n");
        printf("8:delete after\n");
        printf("9:exit\n");
        printf("Enter your choice  : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                start = create(start);
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                start = insertbeg(start);
                break;
            case 4:
                start = insertend(start);
                break;
            case 5:
                start = insertbefore(start);
                break;
            case 6:
                start = deletebeg(start);
                break;
            case 7:
                start = deleteend(start);
                break;
            case 8:
                start = deleteafter(start);
                break;
        }
    } while (ch != 9);
    return 0;
}