//author @Nishant

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

void append(Node **root, int data);
int commonAncestor(Node *root, int x, int y);

int main(){
    Node *root = NULL;
    int data, x, y;
    while(1){
        cin >> data;
        if(data >= 0){
            append(&root, data);
        }else{
            break;
        } 
    }
    cout << "Enter the value of n1 and n2: " << endl;
    cin >> x >> y;
    cout << "Common ancestor of " << x << " and " << y << " is " << commonAncestor(root, x, y);
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

int commonAncestor(Node *root, int x, int y){
    if(x>root->data && y>root->data){
        commonAncestor(root->right, x, y);
    }else if(x<root->data && y<root->data){
        commonAncestor(root->left, x, y);
    }else{
        return root->data;
    }
}
