#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};
Node *head = NULL;

void print(){
    Node *node = head;
    while(node != NULL){
        cout << node->data << endl;
        node = node->next;
    }
}

void insert(int value){
    Node *last = head;
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return;
    }else{
        while(last->next != NULL)
            last = last->next;
        last->next = newNode;  
        return;
    }
}

void deleteF(){
    Node *temp = new Node;
    temp = head;
    head = head->next;
    free(temp);
}

int main(){
    int elements;
    while(1){
        cin >> elements;
        if(elements >= 0)
            insert(elements);
        else
            break;
    }
    deleteF();
    print();
    return 0;
}