#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define STACKSIZE 1000
struct stack
{
    int size;
    int bowels[STACKSIZE];
};

void push(struct stack *koval, int nova)
{
    if (koval->size >= STACKSIZE)
    {
        printf("Stack is full");
    }
    else
    {
        koval->bowels[koval->size] = nova;
        koval->size++;
    }

}

int pop(struct stack *koval)
{
    if (koval->size == 0)
    {
        printf("Stack is empty");
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
        if ((size > 1) || (actual[0] <= '9' && actual[0] >= '0') )
        {
            rez = atoi(actual);
            push(&kovalkulyator, rez);
        }
        else
        {
            if (size == 1 && kovalkulyator.size == 2)
            {
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
                    break;
             default:
                    printf("unknown");
                }
            }
        }
        if (actual[0] == '=')
        {
            result = pop(&kovalkulyator);
            printf("%d\n", result);
        }
    }
    return 0;
}
