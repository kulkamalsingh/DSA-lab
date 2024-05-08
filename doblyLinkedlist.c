#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertAtBeginning(struct Node **head_ref, int new_data);
void insertAtEnd(struct Node **head_ref, int new_data);
void deleteFromBeginning(struct Node **head_ref);
void deleteFromEnd(struct Node **head_ref);
void display(struct Node *node);
void doublyLinkedList();

int main()
{
    doublyLinkedList();
    return 0;
}

void insertAtBeginning(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
    printf("Node inserted at the beginning successfully.\n");
}

void insertAtEnd(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        printf("Node inserted at the end successfully.\n");
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
    printf("Node inserted at the end successfully.\n");
}

void deleteFromBeginning(struct Node **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node *temp = *head_ref;
    *head_ref = (*head_ref)->next;
    if (*head_ref != NULL)
        (*head_ref)->prev = NULL;
    free(temp);
    printf("Node deleted from the beginning successfully.\n");
}

void deleteFromEnd(struct Node **head_ref)
{
    if (*head_ref == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node *last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    if (last->prev == NULL)
        *head_ref = NULL;
    else
        last->prev->next = NULL;
    free(last);
    printf("Node deleted from the end successfully.\n");
}

void display(struct Node *node)
{
    printf("Doubly Linked List: ");
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void doublyLinkedList()
{
    struct Node *head = NULL;
    int choice, data;

    do
    {
        // Display the doubly linked list menu
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete from beginning\n");
        printf("4. Delete from end\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            deleteFromBeginning(&head);
            break;
        case 4:
            deleteFromEnd(&head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            printf("Exiting program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (1);
}
