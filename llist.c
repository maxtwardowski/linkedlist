#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char string[50];
    struct Node * next;
} Node;

Node * init();
int length(Node * list);
void display(Node * list);
void push(Node ** list, char * str);
Node * pop(Node * list);
void destroy(Node * list);
void append(Node * list, char * str);
Node * copy(Node * list);
void reverse(Node * list);
void sort(Node * list);

int main(int argc, char const *argv[]) {
    Node * mylist = init();
    append(mylist, "kurwa");
    append(mylist, "chuj");
    append(mylist, "dupa");
    append(mylist, "ks");
    display(mylist);
    destroy(mylist);
    return 0;
}

Node * init() {
    Node * newlist = malloc(sizeof(Node));
    newlist -> string[0] = '\0';
    newlist -> next = NULL;
    return newlist;
}

int length(Node * list) {
    int listlen = 1;
    Node * node = list;
    while (node -> next != NULL) {
        listlen++;
        node = node -> next;
    }
    return listlen;
}

void display(Node * list) {
    Node * node = list;
    int elemno = 0;
    while (node != NULL) {
        elemno++;
        printf("Element %d: %s\n", elemno, node -> string);
        node = node -> next;
    }
}

void push(Node ** list, char * str) {
    if ((* list) -> next == NULL && !strcmp((* list) -> string, ""))
        strcpy((* list) -> string, str);
    else {
        Node * node = malloc(sizeof(Node));
        strcpy(node -> string, str);
        node -> next = * list;
        * list = node;
    }
}

void destroy(Node * list) {
    Node * node = list;
    Node * curr;
    while ((curr = node) != NULL) {
        node = node -> next;
        free(curr);
    }
}

void append(Node * list, char * str) {
    if (list -> next == NULL && !strcmp(list -> string, ""))
        strcpy(list -> string, str);
    else {
        Node * node = list;
        while (node -> next != NULL)
            node = node -> next;
        node -> next = malloc(sizeof(Node));
        node -> next -> next = NULL;
        strcpy(node -> next -> string, str);
    }
}

Node * copy(Node * list) {
    Node * duplicate = malloc(sizeof(Node));
    memcpy(duplicate, list, sizeof(Node));
    return duplicate;
}
