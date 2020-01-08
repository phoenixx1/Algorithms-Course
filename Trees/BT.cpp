//author @Nishant

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

void append(Node **root, int data);
void printInorder(Node *root);

int main(){
    Node *root = NULL;
    int data, s;
    while(1){
        cin >> data;
        if(data >= 0){
            append(&root, data);
        }else{
            break;
        } 
    }
    cout << "Tree values are:" << endl;
    printInorder(root);
    return 0;
}

void append(Node **root, int data){
    Node *temp, *newNode;
    temp = *root;
    newNode = new Node;
    newNode->left = NULL;
    newNode->data = data;
    newNode->right = NULL;
    if(*root==NULL){
        *root=newNode;
    }else{
        while(1){
            if(temp->left==NULL){
                temp->left = newNode;
                break;
            }else if(temp->right==NULL){
                temp->right = newNode;
                break;
            }else{
                temp = temp->left;
            }
        }
    }
}

void printInorder(Node *root){
    if(root==NULL)
        return;
    else
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
}
