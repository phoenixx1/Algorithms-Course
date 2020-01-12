#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head = NULL;

int n = 1;

void print(){
    struct Node *node;
    node = head;
    while(node != NULL){
        printf("%d ",node->data);
        node = node->next;
    }
}

void insertL(int value){
    struct Node *last = (struct Node *)malloc(sizeof(struct Node));
    last = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
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

void reverse(){
    struct Node *prev, *curr, *temp;
    if(head!=NULL){
        prev = head;
        curr = head->next;
        temp = head->next;
        prev->next = NULL;
        while(temp!=NULL){
            temp = temp->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        temp = prev;
    }
    head = temp;
}

int main(){
    int elements;
    while(1){
        scanf("%d", &elements);
        if(elements>=0){
            insertL(elements);
        }else{
            break;
        }
    }
    if(n==1){
        printf("No value has been inserted");
        return 0;
    }
    printf("Original Order:\n");
    print();
    reverse();
    
    printf("\nReverse Order:\n");
    print();
    return 0;
}