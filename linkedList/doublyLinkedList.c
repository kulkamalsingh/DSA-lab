#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct Node
{
   int data;
   struct Node *prev;
   struct Node *next;
};

// Function prototypes
void insertAtBeginning(struct Node **head_ref, int new_data);
void insertAtEnd(struct Node **head_ref, int new_data);
void insertAtMiddle(struct Node **head_ref, int new_data, int position);
void deleteFromBeginning(struct Node **head_ref);
void deleteFromEnd(struct Node **head_ref);
void deleteFromMiddle(struct Node **head_ref, int position);
void display(struct Node *node);
void traverseFromNode(struct Node *node);
void doublyLinkedList();

int main()
{
   doublyLinkedList();
   return 0;
}

// Function to insert a new node at the beginning of the doubly linked list
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

// Function to insert a new node at the end of the doubly linked list
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

// Function to insert a new node at a given position in the doubly linked list
void insertAtMiddle(struct Node **head_ref, int new_data, int position)
{
   if (position < 1)
   {
      printf("Invalid position! Position should be greater than or equal to 1.\n");
      return;
   }
   struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
   new_node->data = new_data;
   if (position == 1)
   {
      new_node->prev = NULL;
      new_node->next = *head_ref;
      if (*head_ref != NULL)
         (*head_ref)->prev = new_node;
      *head_ref = new_node;
      printf("Node inserted at position %d successfully.\n", position);
      return;
   }
   struct Node *current = *head_ref;
   for (int i = 1; i < position - 1 && current != NULL; i++)
      current = current->next;
   if (current == NULL)
   {
      printf("Invalid position! Position exceeds the length of the list.\n");
      return;
   }
   new_node->next = current->next;
   if (current->next != NULL)
      current->next->prev = new_node;
   current->next = new_node;
   new_node->prev = current;
   printf("Node inserted at position %d successfully.\n", position);
}

// Function to delete a node from the beginning of the doubly linked list
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

// Function to delete a node from the end of the doubly linked list
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

// Function to delete a node from a given position in the doubly linked list
void deleteFromMiddle(struct Node **head_ref, int position)
{
   if (*head_ref == NULL)
   {
      printf("List is empty. Nothing to delete.\n");
      return;
   }
   if (position < 1)
   {
      printf("Invalid position! Position should be greater than or equal to 1.\n");
      return;
   }
   struct Node *current = *head_ref;
   if (position == 1)
   {
      *head_ref = (*head_ref)->next;
      if (*head_ref != NULL)
         (*head_ref)->prev = NULL;
      free(current);
      printf("Node deleted from position %d successfully.\n", position);
      return;
   }
   for (int i = 1; current != NULL && i < position; i++)
      current = current->next;
   if (current == NULL)
   {
      printf("Invalid position! Position exceeds the length of the list.\n");
      return;
   }
   if (current->next != NULL)
      current->next->prev = current->prev;
   if (current->prev != NULL)
      current->prev->next = current->next;
   free(current);
   printf("Node deleted from position %d successfully.\n", position);
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

void traverseFromNode(struct Node *node)
{
   printf("Traversal from the given node: ");
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
   int choice, data, position;

   do
   {
      printf("\nDoubly Linked List Operations:\n");
      printf("1. Insert at beginning\n");
      printf("2. Insert at end\n");
      printf("3. Insert at middle\n");
      printf("4. Delete from beginning\n");
      printf("5. Delete from end\n");
      printf("6. Delete from middle\n");
      printf("7. Display\n");
      printf("8. Traverse from a node\n");
      printf("9. Exit\n");
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
         printf("Enter data to insert: ");
         scanf("%d", &data);
         printf("Enter position to insert: ");
         scanf("%d", &position);
         insertAtMiddle(&head, data, position);
         break;
      case 4:
         deleteFromBeginning(&head);
         break;
      case 5:
         deleteFromEnd(&head);
         break;
      case 6:
         printf("Enter position to delete: ");
         scanf("%d", &position);
         deleteFromMiddle(&head, position);
         break;
      case 7:
         display(head);
         break;
      case 8:
         printf("Enter position to start traversal from: ");
         scanf("%d", &position);
         struct Node *current = head;
         for (int i = 1; i < position && current != NULL; i++)
            current = current->next;
         if (current == NULL)
            printf("Invalid position! Position exceeds the length of the list.\n");
         else
            traverseFromNode(current);
         break;
      case 9:
         printf("Exiting program. Goodbye!\n");
         exit(0);
      default:
         printf("Invalid choice! Please enter a number between 1 and 9.\n");
      }
   } while (1);
}
