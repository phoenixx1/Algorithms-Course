#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

void print(Node *node){
    while(node != NULL){
        cout << node->data << "->";
        node = node->next;
    }
    cout << "NULL";
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

Node *newNode(int value){
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    return temp;
}

Node *sort(Node *head1, Node *head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    Node* h = newNode(0);
    Node* temp=h;
    Node* h1=head1;
    Node* h2=head2;
    while(h1!=NULL && h2!=NULL){
        if(h1->data>=h2->data){ 
            Node* temp2 = newNode(h2->data);
            temp->next=temp2;
            temp=temp->next;
            h2=h2->next;
        }else if(h1->data<h2->data){ 
            Node* temp2=newNode(h1->data);
            temp->next=temp2;
            temp=temp->next;
            h1=h1->next;
        }
    }
    while(h1!=NULL)
    {
        Node* temp2=newNode(h1->data);
        temp->next=temp2;
        temp=temp->next;
        h1=h1->next;
    }
    while(h2!=NULL)
    {
        Node* temp2 = newNode(h2->data);
        temp->next=temp2;
        temp=temp->next;
        h2=h2->next;
    }
    h=h->next;
    return h;
}

int main(){
    Node *head1 = NULL;
    Node *head2 = NULL;
    int elements, n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> elements;
        insert(&head1, elements);
    }
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> elements;
        insert(&head2, elements);
    }
    Node *head = sort(head1, head2);
    print(head);
    
}