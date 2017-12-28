#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define STACKSIZE 1000
struct stack
{
    int size;
    int bowels[STACKSIZE];
};

void push(struct stack *koval, int nova)    /* function push that puts element in stack */
{
    if (koval->size == STACKSIZE)   /* check overflow */
    {
        printf("Error");
    }
    else
    {
        koval->bowels[koval->size] = nova;
        koval->size++;
    }

}

int pop(struct stack *koval)    /*function pop that returns last element in stack*/
{
    if (koval->size == 0)   /*check underflow*/
    {
        printf("Error");
        return 0;
    }
    else
    {
        koval->size--;
        return koval->bowels[koval->size];
    }

}

int main()
{
    struct stack kovalkulyator;
    kovalkulyator.size = 0;
    char actual[100];
    int result, size, rez;
    int a, b;
    while (scanf("%s", actual) != EOF)
    {

        size = strlen(actual);
        if ((size > 1) || (actual[0] <= '9' && actual[0] >= '0') ) /*check if element is number*/
        {
            rez = atoi(actual);
            push(&kovalkulyator, rez);
        }
        else
        {
            if (size == 0)
                break;
            b = pop(&kovalkulyator);
            a = pop(&kovalkulyator);
            switch(actual[0])
            {
            case '+':
                push(&kovalkulyator, a + b);
                break;
            case '-':
                push(&kovalkulyator, a - b);
                break;
            case '*':
                push(&kovalkulyator, a * b);
                break;
            case '/':
                push(&kovalkulyator, a / b);
            default:
                printf("error");
            }

        }
    }
    result = pop(&kovalkulyator);
    printf("%d", result);
    return 0;
}

