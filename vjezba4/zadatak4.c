#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial* position;
struct polynomial {
    int coefficient;
    int exponent;
    position next;
};

int addFirst(position);
int addSecond(position);
int printPolynomial(position);


int main() {
    struct polynomial Head1;
    struct polynomial Head2;
    Head1.next = NULL;
    Head2.next = NULL;
    addFirst(&Head1);
    addSecond(&Head2);
    printf("Printing the first polynomial:\n\n");
    printPolynomial(Head1.next);
    printf("Printing the second polynomial:\n\n");
    printPolynomial(Head2.next);
    
    return 0;
}

int addFirst(position p) {
    FILE* fp = NULL;
    fp = fopen("pol1.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file!\n");
        return 1;
    }
    while (!feof(fp)) {
        position q = NULL;
        q = (position)malloc(sizeof(struct polynomial));
        if (q == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        position prev, temp;
        temp = p->next;
        prev = p;
        fscanf(fp, "%d %d", &q->coefficient, &q->exponent);
        while (temp != NULL && temp->exponent < q->exponent) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = q;
        if (temp != NULL)
            q->next = temp;
        else
            q->next = NULL;
    }
    return 0;
}

int addSecond(position p) {
    FILE* fp = NULL;
    fp = fopen("pol2.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file!\n");
        return 1;
    }
    while (!feof(fp)) {
        position q = NULL;
        q = (position)malloc(sizeof(struct polynomial));
        if (q == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        position prev, temp;
        temp = p->next;
        prev = p;
        fscanf(fp, "%d %d", &q->coefficient, &q->exponent);
        while (temp != NULL && temp->exponent < q->exponent) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = q;
        if (temp != NULL)
            q->next = temp;
        else
            q->next = NULL;
    }
    return 0;
}

int printPolynomial(position p) {
    while (p != NULL) {
        printf("Coefficient: %d Exponent: %d\n", p->coefficient, p->exponent);
        p = p->next;
    }
    return 0;
}
