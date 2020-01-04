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
        cout << node->data << endl;
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

void deleteN(Node **head, int value){
    Node *temp = *head, *prev;
    if (temp != NULL && temp->data == value){ 
        *head = temp->next;   
        free(temp);                
        return; 
    }
    while (temp != NULL && temp->data != value){ 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) 
        return; 
    prev->next = temp->next; 
    free(temp);
}

int main(){
    Node *head = NULL;
    int elements;
    while(1){
        cin >> elements;
        if(elements >= 0)
            insert(&head, elements);
        else
            break;
    }
    print(head);
    cin >> elements;
    deleteN(&head, elements);
    cout << endl;
    print(head);
    return 0;
}
