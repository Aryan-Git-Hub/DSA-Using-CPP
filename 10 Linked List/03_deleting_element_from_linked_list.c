#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* previous;
    struct Node* next;
};

void display(struct Node** Head, struct Node** temp) {
    // printing elements of linked list
    *temp = *Head;
    while(*temp)
    {
        printf("%p %d\n", (*temp)->next, (*temp)->data);
        *temp = (*temp)->next;
    }
}

int main() {
    struct Node* Head;
    Head = NULL;

    // adding elements to linked list
    struct Node* temp, *tail;
    for (int i = 1; i <= 10; i++)
    {
        if (Head==NULL)
        {
            Head = (struct Node*) malloc(sizeof(struct Node));
            Head->data = i;
            Head->previous = NULL;
            Head->next = NULL;
            tail = Head;
        }
        else
        {
            temp = (struct Node*) malloc(sizeof(struct Node));
            temp->data = i;
            temp->previous = tail;
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
        }
    }

    // deleting element from linked list
    int position;
    printf("Enter the position of element to delete: ");
    scanf("%d", &position);

    if (position==1) {
        temp = Head->next;
        free(Head);
        Head = temp;
    } else {
        struct Node* curr = Head, *prev = NULL;
        for (int i = 0; i < position-1; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        free(curr);
    }

    // printing elements of linked list
    display(&Head, &temp);

    return 0;
}