#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char string[50];
    struct node * next;
} Node;

Node * init();
int length(Node * list);
void display(Node * list);
void push(Node * list);
Node * pop(Node * list);
void destroy(Node * list);
void append(Node * list);
Node * copy(Node * list);
void reverse(Node * list);
void sort(Node * list);

int main(int argc, char const *argv[]) {

    return 0;
}

Node * init() {
    Node * newlist = malloc(sizeof(newlist));
    newlist -> string[0] = '\0';
    return newlist;
}
