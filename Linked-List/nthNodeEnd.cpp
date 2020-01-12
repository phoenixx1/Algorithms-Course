#include<bits/stdc++.h>
using namespace std;
static int n = 1;

class Node{
    public:
        int data;
        Node *next;
}*head = NULL;


void print(){
    Node *node = head;
    while(node != NULL){
        cout << node->data << " ";
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
        n++;
    }else{
        while(last->next != NULL)
            last = last->next;
        last->next = newNode;
        n++;  
        return;
    }
}

bool search(int value){
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

int nFromEnd(int pos){
    Node *temp = head;
    if(n<pos){
        return 0;
    }
    for(int i=1; i<=n-pos; i++){
        temp = temp->next;
    }
    return temp->data;
    
}

int main(){
    Node *head = NULL;
    int elements, pos;
    
    while(1){
        cin >> elements;
        if(elements >= 0){
            insert(elements);
        }else{
            break;
        }
    }
    cin >> pos;
    pos = nFromEnd(pos);
    cout << "Enter the nth node:" << endl;
    if(pos != 0)
        cout << pos << " is the nth node element in the list";
    else
        cout << "There is no nth node in the list";
    cout << endl;
    return 0;
}