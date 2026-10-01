#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- Singly Circular List ---------- */

struct SNode {
    char name[20];
    struct SNode *next;
};

struct SNode *shead = NULL;

void sInsert(char name[]) {
    struct SNode *n = malloc(sizeof(struct SNode));
    strcpy(n->name, name);

    if (shead == NULL) {
        shead = n;
        n->next = shead;
        return;
    }

    struct SNode *temp = shead;
    while (temp->next != shead)
        temp = temp->next;

    n->next = shead;
    temp->next = n;
}

void sDelete(char name[]) {
    if (shead == NULL)
        return;

    struct SNode *temp = shead, *prev = NULL;

    do {
        if (strcmp(temp->name, name) == 0) {
            if (temp == shead) {
                if (shead->next == shead) {
                    shead = NULL;
                } else {
                    struct SNode *last = shead;
                    while (last->next != shead)
                        last = last->next;

                    shead = shead->next;
                    last->next = shead;
                }
            } else {
                prev->next = temp->next;
            }

            free(temp);
            return;
        }

        prev = temp;
        temp = temp->next;
    } while (temp != shead);
}

void sDisplay() {
    if (shead == NULL) {
        printf("Empty\n");
        return;
    }

    struct SNode *temp = shead;

    do {
        printf("%s ", temp->name);
        temp = temp->next;
    } while (temp != shead);

    printf("\n");
}


/* ---------- Doubly Circular List ---------- */

struct DNode {
    char name[20];
    struct DNode *prev, *next;
};

struct DNode *dhead = NULL;

void dInsert(char name[]) {
    struct DNode *n = malloc(sizeof(struct DNode));
    strcpy(n->name, name);

    if (dhead == NULL) {
        dhead = n;
        n->next = n;
        n->prev = n;
        return;
    }

    struct DNode *last = dhead->prev;

    n->next = dhead;
    n->prev = last;
    last->next = n;
    dhead->prev = n;
}

void dDelete(char name[]) {
    if (dhead == NULL)
        return;

    struct DNode *temp = dhead;

    do {
        if (strcmp(temp->name, name) == 0) {

            if (temp->next == temp) {
                dhead = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == dhead)
                    dhead = temp->next;
            }

            free(temp);
            return;
        }

        temp = temp->next;
    } while (temp != dhead);
}

void dDisplay() {
    if (dhead == NULL) {
        printf("Empty\n");
        return;
    }

    struct DNode *temp = dhead;

    do {
        printf("%s ", temp->name);
        temp = temp->next;
    } while (temp != dhead);

    printf("\n");
}


/* ---------- Main ---------- */

int main() {

    printf("Singly Circular List:\n");

    sInsert("A");
    sDisplay();

    sInsert("B");
    sDisplay();

    sInsert("C");
    sDisplay();

    sDelete("B");
    sDisplay();


    printf("\nDoubly Circular List:\n");

    dInsert("A");
    dDisplay();

    dInsert("B");
    dDisplay();

    dInsert("C");
    dDisplay();

    dDelete("B");
    dDisplay();

    return 0;
}