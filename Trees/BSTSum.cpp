//author @Nishant

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

void append(Node **root, int data);
int addT(Node *root);

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
    cout << "Sum of all nodes are " << addT(root);
    
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
            if(data>temp->data){
                if(temp->right!=NULL){
                    temp = temp->right;
                }else{
                    temp->right = newNode;
                    break;
                }
            }else{
                if(temp->left!=NULL){
                    temp = temp->left;
                }else{
                    temp->left=newNode;
                    break;
                }
            }
        }
    }
}

int addT(Node *root){
    if(root==NULL)
        return 0;
    else
        return (root->data + addT(root->left)+addT(root->right));
}
