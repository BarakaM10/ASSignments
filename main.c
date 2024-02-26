#include <stdio.h>
#include <stdlib.h>

struct node{
    int number;
    struct node*next;
};
struct node* createNode(int num){
    struct node *new_node= malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Error in allocating memory!");
        exit(1);
    }
    new_node->number=num;
    new_node->next=NULL;
    return new_node;
}

void append(struct node**head, int num){
    struct node *new_node= createNode(num);
    if(*head==NULL){
        *head=new_node;
        return;
    }
    struct node* current= *head;
    while(current->next!=NULL){
        current= current->next;
    }
    current->next=new_node;
}

void prepend(struct node**head, int num){
    struct node *new_node= createNode(num);
    new_node= createNode(num);
    new_node->next=*head;
    *head= new_node;
}

void printList(struct node*head){
    struct node *current = head;
    printf("[");
    while(current != NULL){
        printf("%d", current->number);
        current=current->next;

        if(current!=NULL){
            printf(",");
        }
    }
    printf("]\n");
}

void deleteKey(struct node**head, int key){
    struct node *current= *head;
    struct node *prev = NULL;
    if(current!=NULL&& current->number==key){
        current=current->next;
        free(current);
    }while(current!=NULL&& current->number!=key){
        current=current->next;
        prev=current;
}   if (current == NULL){
        printf("key not found in the list");
        return;}
    prev->next = current->next;
    free(current);

}
void deleteByValue(struct node **head, int value){
    struct node *current = *head;
    struct node *prev = NULL;
    if(current != NULL && current->number == value){
        *head = current-> next;
        free(current);
        return;
}
    while(current != NULL && current->number != value){
        prev = current;
        current = current->next;
    }

    if(current == NULL){
        printf("value not found");
        return;
}
    prev->next = current->next;
    free(current);

}

void insertAfterKey(struct node **head, int key, int value)
{
    struct node *current = *head;
    if(current != NULL && current->number != key){
        struct node *new_node = createNode(value);
        current->next = new_node;
        return;
    }
    while (current != NULL && current->number != key)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        return;
    }
    struct node *new_node = createNode(value);
    new_node->next = current->next;
    current->next = new_node;

}
void insertAfterValue(struct node **head, int searchValue, int newValue)
{
    struct node *current = *head;
     if(current != NULL && current->number != newValue){
        struct node *new_node = createNode(newValue);
        current->next = new_node;
        return;
    }
    while (current != NULL && current->number != newValue)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        return;
    }

    struct node *new_node = createNode(newValue);
    new_node->next = current->next;
    current->next = new_node;
}

int main()
{
    struct Node *head = NULL;
    int choice, data;

    while (1)
    {
        printf("Linked Lists\n");
        printf("1. Print List\n");
        printf("2. Append\n");
        printf("3. prepend\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch(choice)
        {case 1:
            printf("Linked List: ");
            printList(head);
            break;
        case 2:
            printf("Enter data to append: ");
            scanf("%d", &data);
            append(&head, data);
            break;
        case 3:
            printf("Enter data to prepend: ");
            scanf("%d", &data);
            prepend(&head, data);
            break;
        case 4:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            deleteByValue(&head, data);
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
            default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}

