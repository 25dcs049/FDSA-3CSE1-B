#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *front = NULL;
void insert(int x)
{
    struct Node *p = malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;

    if(front == NULL)
        front = p;
    else {
        struct Node *t = front;
        while(t->next) t = t->next;
        t->next = p;
    }
}
void delete(int x)
{
    struct Node *t = front, *p = NULL;
    while(t && t->data != x)
        p = t, t = t->next;
    if(!t) return;
    if(p) p->next = t->next;
    else front = t->next;
    free(t);
}

void show(struct Node *t)
{
    if(!t) return;
    printf("%d ", t->data);
    show(t->next);
}
void reverse(struct Node *t)
{
    if(!t) return;
    reverse(t->next);
    printf("%d ", t->data);
}

int main()
{
    int n, x;
    printf("Enter number of patients: ");
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &x);
        insert(x);
    }

    printf("Queue: ");
    show(front);
    printf("\nDelete token: ");
    scanf("%d", &x);
    delete(x);
    printf("Queue: ");
    show(front);
    printf("\nReverse: ");
    reverse(front);

    return 0;
}