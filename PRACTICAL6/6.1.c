#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;
void place(int tray)
{
    if (top == MAX - 1)
        printf("Error: Stack is full!\n");
    else
    {
        top++;
        stack[top] = tray;
        printf("Placed: %d\n", tray);
    }
}

void take()
{
    if (top == -1)
        printf("Error: Stack is empty!\n");
    else
    {
        printf("Taken: %d\n", stack[top]);
        top--;
    }
}

void showTop()
{
    if (top == -1)
        printf("Top: Empty\n");
    else
        printf("Top tray: %d\n", stack[top]);
}

int main()
{
    place(10);
    showTop();
    place(20);
    showTop();
    take();
    showTop();
    take();
    showTop();
    take();  
    return 0;
}