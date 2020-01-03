//Insert element in linked list at the end

//author @Nishant

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

void print(Node *node){
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
}

void insert(Node **head, int value){
    Node *last = *head;
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }else{
        while(last->next != NULL)
            last = last->next;
        last->next = newNode;  
        return;
    }
}

int main(){
    Node *head = NULL;
    int elements;
    cout << "Enter elements in linked list" << endl;
    while(1){
        cin >> elements;
        if(elements >= 0){
            insert(&head, elements);
        }else{
            break;
        }
    }
    cout << "Entered Linked List" << endl;
    print(head);
    cout << endl;
    return 0;
}
