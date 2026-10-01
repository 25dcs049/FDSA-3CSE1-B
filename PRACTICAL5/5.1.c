#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char song[50];
    struct Node *prev, *next;
};

struct Node *head = NULL;

void addFirst(char name[]) {
    struct Node *newNode = malloc(sizeof(struct Node));
    strcpy(newNode->song, name);

    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void addLast(char name[]) {
    struct Node *newNode = malloc(sizeof(struct Node));
    strcpy(newNode->song, name);
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(char after[], char name[]) {
    struct Node *temp = head;

    while (temp != NULL && strcmp(temp->song, after) != 0)
        temp = temp->next;

    if (temp == NULL) {
        printf("Song not found!\n");
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    strcpy(newNode->song, name);

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void deleteFirst() {
    if (head == NULL)
        return;

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

void display() {
    struct Node *temp = head;

    printf("Playlist: ");
    while (temp != NULL) {
        printf("%s ", temp->song);
        temp = temp->next;
    }
    printf("\n");
}

void countSongs() {
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total songs: %d\n", count);
}

int main() {
    addFirst("SongA");
    display();

    addLast("SongB");
    display();

    insertAfter("SongA", "SongC");
    display();

    countSongs();

    deleteFirst();
    display();

    insertAfter("SongX", "SongD");
    display();

    return 0;
}