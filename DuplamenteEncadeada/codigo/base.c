#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int number;
    struct node *next;
    struct node *previous;
} node;

node *createNode(int value){
    node *newNode = malloc(sizeof(node));
    newNode -> number = value;
    newNode -> next = NULL;
    newNode -> previous = NULL;
}

void insertOnTheEnd(node *firstNode, int value){
    node *newNode = createNode(value);
    node *current = firstNode;

    while (current -> next != NULL)
        current = current -> next;
    
    current -> next = newNode;
    newNode -> previous = current;
}

node *InsertOnTheBeginning(node *firstNode, int value){
    node *newNode = createNode(value);
    newNode -> next = firstNode;
    firstNode -> previous = newNode;
    return newNode;
}

node *InsertOnTheMiddle(node *firstNode, int index, int value){
    node *current = firstNode;
    int listSize = 0;

    while (current != NULL){
        listSize += 1;
        current = current -> next;
    }
    current = firstNode;

    if(index == 0){
        firstNode = InsertOnTheBeginning(firstNode, value);
    }else{
        if(index > 0){
            if(index >= listSize){
                insertOnTheEnd(firstNode, value);
            }else{
                node *newNode = createNode(value);
                for(int i = 0; i < index-1; i++){
                    current = current -> next;
                }
                newNode -> previous = current;
                newNode -> next = current -> next;
                newNode -> next -> previous = newNode;
                current -> next = newNode;
            }
        }
    }
    return firstNode;
}

node *deleteFromIndex(node *firstNode, int index){
    node *current = firstNode;
    int listSize = 0;

    while (current != NULL){
        listSize += 1;
        current = current -> next;
    }
    current = firstNode;

    if(index >= 0 && index < listSize){
        if(index == 0){
            node *newFirstNode = firstNode -> next;
            newFirstNode -> previous = NULL;
            free(firstNode);
            firstNode = newFirstNode;
            
        }else if(index == listSize - 1){
            while (current -> next != NULL){
                current = current -> next;
            }
            node *newLastNode = current -> previous;
            newLastNode -> next = NULL;
            free(current);
        }else{
            for(int i = 0; i < index; i++){
                current = current -> next;
            }
            current -> previous -> next = current -> next;
            current -> next -> previous = current -> previous;

            free(current);
        }
    }
    return firstNode;
}

node *deleteFromNode(node *currentNode){
    if(currentNode -> previous == NULL){
        node *newFirstNode = currentNode -> next;
        newFirstNode -> previous = NULL;
        free(currentNode);
        currentNode = newFirstNode;
    }else if(currentNode -> next == NULL){
        node *newLastNode = currentNode -> previous;
        newLastNode -> next = NULL;
        free(currentNode);
        currentNode = newLastNode;
        while (currentNode -> previous != NULL)
            currentNode = currentNode -> previous;
    }else{
        node *previous = currentNode -> previous;
        previous -> next = currentNode -> next;
        currentNode -> next -> previous = previous;
        free(currentNode);
        currentNode = previous -> next;
    }
    return currentNode;
}

void printList(node *firstNode){
    node *current = firstNode;

    while (current != NULL)
    {
        printf("%d ", current -> number);
        current = current -> next;
    }
    printf("\n");
    
}

int main(){
    node *firstNode = createNode(0);
    insertOnTheEnd(firstNode, 1);
    insertOnTheEnd(firstNode, 2);
    insertOnTheEnd(firstNode, 3);
    insertOnTheEnd(firstNode, 4);
    insertOnTheEnd(firstNode, 5);
    firstNode = InsertOnTheMiddle(firstNode, 2, 7);
    firstNode = InsertOnTheBeginning(firstNode, 6);

    printList(firstNode);
}