/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode *root = NULL;
        for(int i = 0; i < n; i++){
            TreeNode *temp, *newNode;
            temp = root;
            newNode = new TreeNode;
            newNode->left = NULL;
            newNode->val = preorder[i];
            newNode->right = NULL;
            if(root==NULL){
                root=newNode;
            }else{
                while(1){
                    if(preorder[i]>temp->val){
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
        return root;
    }
};