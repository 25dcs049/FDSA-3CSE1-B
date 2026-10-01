#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stack[100];
int top = -1;
void visit(char page[])
{
    top++;
    stack[top] = malloc(strlen(page) + 1);
    strcpy(stack[top], page);
    printf("Visited: %s\n", page);
    printf("Current page: %s\n", stack[top]);
}
void back()
{
    if (top == 0)
        printf("Error: No previous page!\n");
    else
    {
        free(stack[top]);
        top--;
        printf("Current page: %s\n", stack[top]);
    }
}

int main()
{
    visit("Google");
    visit("YouTube");
    visit("Instagram");
    back();
    back();
    back();  
    return 0;
}