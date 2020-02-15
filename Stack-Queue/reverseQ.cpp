#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        Node *next;
}*front = NULL, *rear = NULL;
int n = 0;
void append(int data){
    Node *temp = front;
    Node *newNode = new Node;
    newNode->next = NULL;
    newNode->data = data;
    if(front == NULL){
        front = rear = newNode;
        n++;
    }
    else{
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        rear = newNode;
        n++;
    }
}

void print(){
    Node *node = front;
    while(node != NULL){
        cout << node->data << " ";
        node = node->next; 
    }
    cout << endl;
}

void reverse(){
    Node *prev = NULL;
    Node *curr = front;
    Node *next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    rear = front;
    front = prev;
}

int main(){
    int data;
    do{
        cin >> data;
        if(data>=0)
            append(data);
    }while(data>=0);
    if(n==0){
        cout << "Queue is empty";
        return 0;
    }
  	cout << "Before reversing:" << endl;
    print();
    reverse();
  	cout << "After reversing:" << endl;
    print();
    return 0;
}