//author @Nishant

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

void append(Node **root, int data);
int maxDepth(Node *node);
int diameter(Node *node);

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
    cout << "Diameter of the given binary tree is " << diameter(root);
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

int maxDepth(Node *node){
    if(node == NULL){
        return 0;
    }else{
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        if(lDepth>rDepth)
            return(lDepth+1);
        else
            return(rDepth+1);
    }
}

int diameter(Node *node){
    return(maxDepth(node->left)+maxDepth(node->right)+1);
}
