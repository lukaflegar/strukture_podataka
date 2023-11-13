/*
Napisati program koji iz datoteke èita postfiks izraz i zatim korištenjem stoga raèuna
rezultat.Stog je potrebno realizirati preko vezane liste.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack* position;
struct stack {
    int el;
    position next;
};

int push(position head, int element);
int pop(position head);
int evaluate(position head);
int sum(position head);
int difference(position head);
int product(position head);
int quotient(position head);

int main()
{
    struct stack Head;
    Head.next = NULL;
    evaluate(&Head);
    if (Head.next != NULL) {
        printf("The result is %d\n", Head.next->el);
    }
    else {
        printf("Stack is empty.\n");
    }
    return 0;
}

int evaluate(position head)
{
    FILE* fp = NULL;
    fp = fopen("postfix.txt", "r");
    char operation[15];

    if (fp == NULL)
    {
        printf("Failed to open the file!\n");
        return 1;
    }

    while (fscanf(fp, "%s", operation) != EOF)
    {
        int num = 0;
        int read = sscanf(operation, "%d", &num);

        if (read == 1) {
            push(head, num);
        }
        else {
            if (strcmp(operation, "+") == 0)
                sum(head);
            else if (strcmp(operation, "-") == 0)
                difference(head);
            else if (strcmp(operation, "*") == 0)
                product(head);
            else if (strcmp(operation, "/") == 0)
                quotient(head);
        }
    }

    fclose(fp);
    return 0;
}

int push(position head, int element)
{
    position newElement;
    newElement = (position)malloc(sizeof(struct stack));
    if (newElement == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    newElement->el = element;
    newElement->next = head->next;
    head->next = newElement;

    return 0;
}

int pop(position head)
{
    position temp = NULL;
    int element;
    if (head->next == NULL)
    {
        printf("The stack is empty!\n");
        return -1;  // Return value indicating an error
    }
    temp = head->next;
    element = temp->el;
    head->next = temp->next;
    free(temp);
    return element;
}

int sum(position head)
{
    int firstNumber = pop(head);
    int secondNumber = pop(head);
    push(head, secondNumber + firstNumber);
    return 0;
}

int difference(position head)
{
    int firstNumber = pop(head);
    int secondNumber = pop(head);
    push(head, secondNumber - firstNumber);
    return 0;
}

int product(position head)
{
    int firstNumber = pop(head);
    int secondNumber = pop(head);
    push(head, secondNumber * firstNumber);
    return 0;
}

int quotient(position head)
{
    int firstNumber = pop(head);
    int secondNumber = pop(head);
    push(head, secondNumber / firstNumber);
    return 0;
}


