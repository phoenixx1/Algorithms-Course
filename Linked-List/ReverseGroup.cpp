#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};
int n = 1;

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
        n++;
        return;
    }else{
        while(last->next != NULL)
            last = last->next;
        last->next = newNode;  
        n++;
        return;
    }
}

Node *reverse(Node *head, int limit){
    struct Node *prev, *curr, *temp;
    curr = head;
    prev = temp = NULL;
    int x = 0;
    while(curr!=NULL && x<limit){
        temp = curr->next;  
        curr->next = prev;  
        prev = curr;  
        curr = temp;  
        x++;  
    }if(temp!=NULL){
        head->next = reverse(temp, limit);
    }
    return prev;
}


int main(){
    int elements, limit;
    Node *head = NULL;
    while(1){
        cin >> elements;
        if(elements >= 0){
            insert(&head, elements);
        }else{
            break;
        }
    }
    cin >> limit;
    head = reverse(head, limit);
    print(head);
    return 0;
}