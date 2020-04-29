//author @Nishant

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

void insert(Node **root, int data){
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

int findMaxUtil(Node* root, int &res) { 
    if (root == NULL) 
        return 0; 
  
    int l = findMaxUtil(root->left,res); 
    int r = findMaxUtil(root->right,res); 
  
    int max_single = max(max(l, r) + root->data, root->data); 
  
    int max_top = max(max_single, l + r + root->data); 
  
    res = max(res, max_top); 

    return max_single; 
} 

int maxPathSum(Node *root){
    int res = INT_MIN; 
    findMaxUtil(root, res); 
    return res; 
}

int main(){
    Node *root = NULL;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        insert(&root, temp);
    }
    cout << maxPathSum(root);
    return 0;
}