#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

void append(Node **head, int data){
    Node *temp = *head; 
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    *head = newNode;
    newNode->next = temp;
}

void print(Node *node){
    while(node != NULL){
        cout << node->data << " ";
        node = node->next; 
    }
}

int main(){
    Node *head = NULL;
    int data;
    while(1){
        cin >> data;
        if(data >= 0){
            append(&head, data);
        }else{
            break;
        } 
    }
    print(head);
    return 0;
}