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
const char * pop(Node * list);
void destroy(Node * list);
void append(Node * list, char * str);
Node * copy(Node * list);
void reverse(Node ** list);
void swapdata(Node * a, Node * b);
void sort(Node * list);

int main(int argc, char const *argv[]) {
    Node * mylist = init();
    append(mylist, "kurwa");
    append(mylist, "chuj");
    append(mylist, "dupa");
    append(mylist, "ks");
    push(&mylist, "njondjkloq2wenlfqe");
    display(mylist);
    printf("===========\n");
    sort(mylist);
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

const char * pop(Node * list) {
    Node * node = list;
    while (true) {
        if (node -> next -> next != NULL)
            node = node -> next;
        else
            break;
    }
    char val[50];
    strcpy(val, node -> next -> string);
    const char * storedval = val;
    free(node -> next);
    node -> next = NULL;
    return storedval;
}

void destroy(Node * list) {
    Node * node = list, * curr;
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
    Node * duplicate = init(), * node = list;
    append(duplicate, node -> string);
    do {
        node = node -> next;
        append(duplicate, node -> string);
    } while (node -> next != NULL);
    return duplicate;
}

void reverse(Node ** list) {
    Node * previous = NULL, * current = * list, * next = NULL;
    while (current != NULL) {
        next  = current -> next;
        current -> next = previous;
        previous = current;
        current = next;
    }
    * list = previous;
}

void swapdata(Node * a, Node * b) {
    char data[50];
    strcpy(data, a -> string);
    strcpy(a -> string, b -> string);
    strcpy(b -> string, data);
}

void sort(Node * list) {
    bool iterneeded = true;
    Node * node = list;

    while (iterneeded) {
        iterneeded = false;
        node = list;
        while (node -> next != NULL) {
            if (strcmp(node -> string, node -> next -> string) > 0) {
                iterneeded = true;
                swapdata(node, node -> next);
            }
            node = node -> next;
        }
    }

}
