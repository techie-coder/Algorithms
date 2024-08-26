#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* createNode(int a) {
    Node* myNode = (Node*)malloc(sizeof(Node));
    myNode->data = a;
    myNode->next = NULL;
    return myNode;
}

Node* traversal(Node* head) {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

void display(Node* head) {
    Node* temp = head;
    printf("List after changing \n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void insertAtEnd(Node* head, int d) {
    Node* newNode = createNode(d);
    Node* end = traversal(head);
    end->next = newNode;
}

void insertAtFirst(Node** head, int d) {
    Node* newNode = createNode(d);
    newNode->next = *head;
    *head = newNode;
}

void insertAfterElement(Node* head, int element, int d){
    Node* newNode = createNode(d);
    Node* temp = head;
    while(temp->data != element){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtPos(Node* head, int pos, int d){
    Node* newNode = createNode(d);
    Node* temp = head;
    int i=0;
    for(int i=0;i<pos-2;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBeforeElement(Node* head, int element, int d){
    Node* newNode = createNode(d);
    Node* temp = head;
    while(temp->next->data != element){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

}

int main()
{
    Node* myNode = createNode(10);
    insertAtEnd(myNode, 25);
    insertAtFirst(&myNode, 20);
    insertAfterElement(myNode, 10, 15);
    display(myNode);
    insertAtPos(myNode,3,23);
    display(myNode);
    insertBeforeElement(myNode,15,47);
    display(myNode);
    // Free the allocated memory
    Node* temp;
    while (myNode != NULL) {
        temp = myNode;
        myNode = myNode->next;
        free(temp);
    }

    return 0;
}