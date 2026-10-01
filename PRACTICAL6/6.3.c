#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;
void push(char ch)
{
    stack[++top] = ch;
}
char pop()
{
    return stack[top--];
}
int priority(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

int main()
{
    char exp[50], postfix[50];
    int i, j = 0;
    char ch;
    printf("Enter expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];
        if (isalnum(ch))
            postfix[j++] = ch;

        else if (ch == '(')
            push(ch);

        else if (ch == ')')
        {
            while (stack[top] != '(')
                postfix[j++] = pop();

            pop();   // remove '('
        }

        else
        {
            while (top != -1 && priority(stack[top]) >= priority(ch))
                postfix[j++] = pop();

            push(ch);
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);
    return 0;
}