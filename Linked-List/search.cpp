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

bool search(Node *head, int value){
    int count = 0;
    Node *temp = head;
    while(temp != NULL){
        if(temp->data == value){
            return 1;
            break;
        }else{
            count++;
            temp = temp->next;
        }
    }
    return 0;
}

int main(){
    Node *head = NULL;
    int elements;
    
    while(1){
        cin >> elements;
        if(elements >= 0){
            insert(&head, elements);
        }else{
            break;
        }
    }
    cin >> elements;
  	cout << "Enter the value to be searched:" << endl;
    if(search(head, elements))
        cout << elements << " is present in the list";
    else
        cout << elements << " is not present in the list";
    cout << endl;
    return 0;
}