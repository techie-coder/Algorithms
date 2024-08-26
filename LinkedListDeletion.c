#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

//Creation of Node
Node* createNode(int a) {
    Node* myNode = (Node*)malloc(sizeof(Node));
    myNode->data = a;
    myNode->next = NULL;
    return myNode;
}

//Traversal to find the end point
Node* traversal(Node* head) {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

//Displaying th entire Linked list
void display(Node* head) {
    Node* temp = head;
    printf("List after changing \n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

//Insertion at end
void insertAtEnd(Node* head, int d) {
    Node* newNode = createNode(d);
    Node* end = traversal(head);
    end->next = newNode;
}

//Insertion at first
/* Explaination provided by https://chat.deepseek.com/coder
Why are we passing the nodes as addresses and not as a struct?
In C, when you pass a variable to a function, it is passed by value. This means that a copy of the variable is made and passed to the function. For simple data types like int or char, this is usually fine, but for more complex data types like structs, this can be inefficient and doesn't allow the function to modify the original data.

When dealing with linked lists, each node is a struct that contains data and a pointer to the next node. If you pass a node by value, you are passing a copy of the node, not the actual node itself. This means any modifications you make to the node inside the function will not affect the original node outside the function.

To allow a function to modify the actual nodes of the linked list, you need to pass pointers to the nodes, not the nodes themselves. Pointers are variables that store the memory address of another variable. By passing a pointer to a node, you are passing the address of the node, which allows the function to access and modify the actual node.*/

void insertAtFirst(Node** head, int d) {
    Node* newNode = createNode(d);
    newNode->next = *head;
    *head = newNode;
}

//Insertion after element
void insertAfterElement(Node* head, int element, int d){
    Node* newNode = createNode(d);
    Node* temp = head;
    while(temp->data != element){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

//Insertion at a particular position
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

//Insertion before an element
void insertBeforeElement(Node* head, int element, int d){
    Node* newNode = createNode(d);
    Node* temp = head;
    while(temp->next->data != element){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

}

//Deletion at end
void delAtEnd(Node* head){
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
}

//deletion at first
void delAtFirst(Node** head){
    Node* temp = (*head)->next;
    *head = temp;
}

//Deletion by element(not deletion of all elements having the same value though)
void delByElement(Node* head, int element){
    Node* temp = head;
    while(temp->next->data != element){
        temp = temp->next;
    }
    Node* newNode = temp->next->next;
    temp->next = newNode;
}

//deletion at specific position
void delAtPos(Node* head, int pos){
    Node* temp = head;
    for(int i=0;i<pos-2;i++){
        temp = temp->next;
    }
    Node* newNode = temp->next->next;
    temp->next = newNode;
}

int main()
{   

    //Testing for my own input
    Node* myNode = createNode(10);
    insertAtEnd(myNode, 25);
    insertAtFirst(&myNode, 20);
    insertAfterElement(myNode, 10, 15);
    display(myNode);
    insertAtPos(myNode,3,23);
    display(myNode);
    insertBeforeElement(myNode,15,47);
    display(myNode);
    delAtEnd(myNode);
    display(myNode);
    delAtFirst(&myNode);
    display(myNode);
    delByElement(myNode,23);
    display(myNode);
    delAtPos(myNode,3);
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