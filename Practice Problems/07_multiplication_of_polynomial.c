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

struct Node* powPresent(struct Node* poly, int pow) {
    struct Node* temp = poly;
    while (temp != NULL) {
        if (temp->pow == pow) return temp;
        temp = temp->next;
    }
    return NULL;
}

void mulPolynomials(struct Node* poly1, struct Node* poly2, struct Node** polyMul) {
    struct Node* temp = poly2;
    while (poly1 != NULL) {
        while (temp != NULL) {
            struct Node* powPresentNode = powPresent(*polyMul, poly1->pow + temp->pow);
            if (powPresentNode) powPresentNode->coeff += poly1->coeff * temp->coeff;
            else createNode(poly1->coeff * temp->coeff, poly1->pow + temp->pow, polyMul);
            temp = temp->next;
        }
        temp = poly2;
        poly1 = poly1->next;
    }


}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *polyMul = NULL;

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

    mulPolynomials(poly1, poly2, &polyMul);

    printf("Multiplication of the polynomials: ");
    displayPoly(polyMul);

    return 0;
}