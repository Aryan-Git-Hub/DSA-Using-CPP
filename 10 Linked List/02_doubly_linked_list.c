#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* previous;
    struct Node* next;
};

int main() {
    struct Node* Head;
    Head = NULL;

    // adding elements to linked list
    struct Node* temp, *tail;
    for (int i = 0; i < 10; i++)
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

    // deleting linked list
    temp = Head;
    struct Node* temp_next;
    for (int i = 0; i < 10; i++)
    {
        temp_next = temp->next;
        free(temp);
        temp = temp_next;
    }

    return 0;
}