#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

void create_linked_list(struct Node** Head, int n) {
    struct Node* previous = NULL, *new_node;
    for (int i = 0; i < n; i++)
    {
        new_node = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &new_node->data);
        if((*Head)==NULL) {
            (*Head) = new_node;
            (*Head)->next = NULL;
            (*Head)->prev = previous;
            previous = *Head;
        } else if(i==n-1) {
            previous->next = new_node;
            new_node->next = *Head;
            (*Head)->prev = new_node;
        } else {
            previous->next = new_node;
            new_node->next = NULL;
            new_node->prev = previous;
            previous = new_node;
        }
    }
}


void display(struct Node* Head) {
    struct Node* temp = Head;
    printf("Your linked list: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp!=Head);
    
    printf("\n");
}


void insert_elem(struct Node** Head, int position, int elem) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)), *prev = (*Head)->prev;
    temp->data = elem;
    if (position==1)
    {
        prev->next = temp;
        temp->prev = prev;
        temp->next = *Head;
        (*Head)->prev = temp;
        (*Head) = temp;
    } else {
        prev = (*Head);
        for (int i = 1; i < position-1; i++) prev = prev->next;
        temp->next = prev->next;
        prev->next->prev = temp;
        prev->next = temp;
        temp->prev = prev;
    }
}


void delete_elem(struct Node** Head, int position) {
    struct Node *temp, *prev;
    if (position==1)
    {
        temp = (*Head)->next;
        prev = (*Head)->prev;
        free((*Head));
        prev->next = temp;
        temp->prev = prev;
        (*Head) = temp;
    } else {
        struct Node *curr = (*Head), *previous, *next;
        for (int i = 1; i < position; i++) curr = curr->next;
        previous = curr->prev;
        next = curr->next;
        previous->next = next;
        next->prev = previous;
        free(curr);
    }
}



int main() {
    struct Node* Head;
    Head = NULL;

    // creating linked list
    int n;
    printf("How many elements you wanna enter: ");
    scanf("%d", &n);
    printf("Enter Elements: ");

    create_linked_list(&Head, n);
    display(Head);

    
    // (a) insert at any node in linked list by taking input from user
    int position, elem;
    printf("Enter position of element for insertion: ");
    scanf("%d", &position);
    printf("Enter Element: ");
    scanf("%d", &elem);

    insert_elem(&Head, position, elem);
    display(Head);


    // (b) deletion of element
    printf("Enter position of element to delete: ");
    scanf("%d", &position);

    delete_elem(&Head, position);
    display(Head);

    return 0;
}