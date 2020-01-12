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
        cout << node->data << endl;
        node = node->next;
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
    while(1){
        cin >> elements;
        if(elements >= 0){
            if(search(head, elements)){
                continue;
            }else{
                insert(&head, elements);
            }
        }else{
            break;
        }
    }
    print(head);
    cout << endl;
    return 0;
}
