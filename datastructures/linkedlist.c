#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *nextPtr;
}Node;

Node *createNode(Node *headNode, int n) {
    Node *newNodePtr = (Node*)malloc(sizeof(headNode));
    newNodePtr->data = n;
    newNodePtr->nextPtr = headNode;
    return newNodePtr;
}

int main() {
    Node *headNode = NULL;
    headNode = createNode(headNode, 5);
    printf("%d", headNode->data);

    free(headNode);
    return 0;
}