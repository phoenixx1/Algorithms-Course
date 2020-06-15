// CPP program demonstrating expectimax algo
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
};
// Creating new node
// Initialising each node will Null value.
struct Node *new_node(int val){
    Node *n = new Node;
    n->key = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}
// Inserting subsequent nodes
struct Node *insert(struct Node *root, int val, queue<Node *> &q){
    Node *node = new_node(val);
    if (root == NULL)
        root = node;

    // left child of the current node
    else if (q.front()->left == NULL)
        q.front()->left = node;

    // right righd of the current node.
    // the Node is poped from the queue after right child is used.
    else
        q.front()->right = node;
        q.pop();
    
    q.push(node);
    return root;
}

// This function calls insert() for all array elements.
Node *Tree(int arr[], int n){
    Node *root = NULL;
    queue<Node *> q1;
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i], q1);
    return root;
}
// Calculating expectimax
float expectimax(Node *node, bool Max){
    // Base case
    if (node->left == NULL && node->right == NULL){
        return node->key;
    }

    // If current call is maximizer node
    // max is chosen from the right or left child.
    if (Max){
        return max(expectimax(node->left, false), expectimax(node->right, false));
    }

    // If the current node is chance node
    // average of the values is returned.
    else{
        return (expectimax(node->left, true) + expectimax(node->right, true)) / 2.0;
    }
}

// Driver code
int main(){
    int arr[] = {0, 0, 0, 10, 12, 30, 130};

    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = Tree(arr, n);
    float utility = expectimax(root, true);
    cout << "Utility is " << utility;

    return 0;
}
