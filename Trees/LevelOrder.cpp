//author @Nishant

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

void append(Node **root, int data);
void printLevelOrder(Node *root);
void printGivenLevel(Node *root, int level);
int maxDepth(Node *node);

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
    cout << "Level order Traversal:" << endl;
    printLevelOrder(root);
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

void printLevelOrder(Node *root){
    int h = maxDepth(root);
    for (int i = 1; i <= h; i++)  
        printGivenLevel(root, i);
}

void printGivenLevel(Node *root, int level){
    if(root==NULL)
        return;
    if(level==1)
        cout << root->data << " ";
    else if(level>1){
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
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
