#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        Node *next;
};

void append(Node **head, char data){
    Node *temp = *head; 
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    *head = newNode;
    newNode->next = temp;
}

void print(Node *node){
    while(node != NULL){
        cout << node->data;
        node = node->next; 
    }
}

int main(){
    Node *head = NULL;
    string str;
    cin >> str;
    cout << str[0];
    for(int i=0; i<str.length(); i++){
        append(&head, str.at(i));
    }
    print(head);
    return 0;
}