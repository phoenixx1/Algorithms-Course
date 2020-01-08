//author @Nishant

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
};

void append(Node **root, int data);
void kthSmallest(Node *root, int k);

int main(){
    Node *root = NULL;
    int data, k;
    while(1){
        cin >> data;
        if(data >= 0){
            append(&root, data);
        }else{
            break;
        } 
    }
    cout << "Enter the kth value:" << endl;
    cin >> k;
    cout << "Smallest kth value ";
    kthSmallest(root, k);
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

void kthSmallest(Node *root, int k){
	static int count = 0;
    if(root==NULL)
        return;
    else
        kthSmallest(root->left, k);
        count++;
        if(count==k){
        	cout << root->data;
        }
        kthSmallest(root->right, k);
}
