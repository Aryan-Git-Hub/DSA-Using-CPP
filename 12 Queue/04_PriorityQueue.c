#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data;
    int priority;
} Element;

Element pq[MAX];
int size = 0;

void insert(int data, int priority) {
    if (size >= MAX) {
        printf("Priority Queue is full!\n");
        return;
    }
    pq[size].data = data;
    pq[size].priority = priority;
    size++;
}

void delete(int data) {
    int i, found = 0;
    for (i = 0; i < size; i++) {
        if (pq[i].data == data) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (int j = i; j < size - 1; j++) {
            pq[j] = pq[j + 1];
        }
        size--;
    } else {
        printf("Element not found!\n");
    }
}

Element peek_max() {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        exit(1);
    }
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i].priority > pq[maxIndex].priority) {
            maxIndex = i;
        }
    }
    return pq[maxIndex];
}

Element extract_max() {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        exit(1);
    }
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i].priority > pq[maxIndex].priority) {
            maxIndex = i;
        }
    }
    Element maxElement = pq[maxIndex];
    delete(pq[maxIndex].data);
    return maxElement;
}

void display() {
    printf("Priority Queue: \n");
    for (int i = 0; i < size; i++) {
        printf("Data: %d, Priority: %d\n", pq[i].data, pq[i].priority);
    }
}

int main() {
    insert(10, 2);
    insert(20, 5);
    insert(30, 1);
    insert(40, 4);

    display();

    printf("\nMax Element: Data = %d, Priority = %d\n", peek_max().data, peek_max().priority);
    printf("Extract Max: Data = %d, Priority = %d\n", extract_max().data, extract_max().priority);
    display();

    delete(30);
    printf("\nAfter Deleting 30:\n");
    display();

    return 0;
}