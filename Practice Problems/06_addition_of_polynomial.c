#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

void createNode(int coeff, int pow, struct Node** poly) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;

    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayPoly(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

void addPolynomials(struct Node* poly1, struct Node* poly2, struct Node** polySum) {
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            createNode(poly1->coeff, poly1->pow, polySum);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            createNode(poly2->coeff, poly2->pow, polySum);
            poly2 = poly2->next;
        } else {
            createNode(poly1->coeff + poly2->coeff, poly1->pow, polySum);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        createNode(poly1->coeff, poly1->pow, polySum);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        createNode(poly2->coeff, poly2->pow, polySum);
        poly2 = poly2->next;
    }
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *polySum = NULL;

    int degree1, degree2, coeff;
    printf("Enter degree of polynomial 1: ");
    scanf("%d", &degree1);
    for (int i = degree1; i >= 0; i--) {
        printf("Enter coeff of x^%d: ", i);
        scanf("%d", &coeff);
        createNode(coeff, i, &poly1);
    }

    printf("Enter degree of polynomial 2: ");
    scanf("%d", &degree2);
    for (int i = degree2; i >= 0; i--) {
        printf("Enter coeff of x^%d: ", i);
        scanf("%d", &coeff);
        createNode(coeff, i, &poly2);
    }

    addPolynomials(poly1, poly2, &polySum);

    printf("Sum of the polynomials: ");
    displayPoly(polySum);

    return 0;
}