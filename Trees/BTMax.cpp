//author @Nishant

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

void append(Node **root, int data);
int maxT(Node *root);

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
    cout << "Maximum element is " << maxT(root);
    
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

int maxT(Node *root){
    if(root == NULL)
        return 0;
    int res = root->data;
    int lres = maxT(root->left);
    int rres = maxT(root->right);
    if(lres > res)
        res = lres;
    if(rres > res)
        res = rres;
    return res;
}
