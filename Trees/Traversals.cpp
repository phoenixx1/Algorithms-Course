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
void printPreorder(Node *root);
void printPostorder(Node *root);

int main(){
    Node *root = NULL;
    int data, n;
    cin >> n;
    for(int i=0; i<n; i++){
            cin >> data;
            append(&root, data);
    }
    cout << "In-Order Traversal: ";
    printInorder(root);
    cout << endl << "Pre-Order Traversal: ";
    printPreorder(root);
    cout << endl << "Post-Order Traversal: ";
    printPostorder(root);
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

void printInorder(Node *root){
    if(root==NULL)
        return;
    else
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
}


void printPreorder(Node *root){
    if(root==NULL)
        return;
    else
        cout << root->data << " ";
        printPreorder(root->left);
        printPreorder(root->right);
}
void printPostorder(Node *root){
    if(root==NULL)
        return;
    else
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->data << " ";
}
