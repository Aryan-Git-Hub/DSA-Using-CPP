#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* Head;
    Head = NULL;

    struct Node* temp;
    struct Node* tail;

    // creating circular linked list
    for (int i = 1; i <= 10; i++)
    {
        if (Head==NULL)
        {
            Head = (struct Node*) malloc(sizeof(struct Node));
            Head->data = i;
            Head->next = NULL;
            tail = Head;
        }
        else
        {
            temp = (struct Node*) malloc(sizeof(struct Node));
            temp->data = i;
            temp->next = Head;
            Head = temp;
        }
    }
    tail->next = Head;

    // free the memory
    temp = Head;
    struct Node* temp_next;
    while (temp!=tail)
    {
        temp_next = temp->next;
        free(temp);
        temp = temp_next;
    }
    free(temp);

    printf("%d\n", Head->data);
    printf("%d\n", temp->data);


    return 0;
}