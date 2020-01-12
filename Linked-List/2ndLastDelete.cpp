#include<bits/stdc++.h>
using namespace std;
static int n = 0;

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

void Delete2ndLast(){
    Node *temp = head;
    if(n==1){
        cout << "\nDeletion of second last element is not possible" << endl;
    }else if(n==2){
        head = temp->next;
        free(temp);
        cout << endl << "After deleting: " << endl;
        print();
    }else{
        for(int i=1; i<=n-3; i++){
            temp = temp->next;
        }
        Node *last = temp->next->next;
        free(temp->next);
        temp->next = last;
        cout << endl << "After deleting: " << endl;
        print();
    }    
}

int main(){
    Node *head = NULL;
    int elements;
    while(1){
        cin >> elements;
        if(elements >= 0){
            insert(elements);
        }else{
            break;
        }
    }
    if(n==0){
        cout << "Deletion of second last element is not possible" << endl;
        return 0;
    }
    cout << "Before deleting:" << endl;
    print();
    Delete2ndLast();
    return 0;
}