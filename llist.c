#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char string[50];
    struct node * next;
} Node;

Node * init();

int main(int argc, char const *argv[]) {

    return 0;
}

Node * init() {
    Node * newlist = malloc(sizeof(newlist));
    newlist -> string[0] = '\0';
    return newlist;
}
