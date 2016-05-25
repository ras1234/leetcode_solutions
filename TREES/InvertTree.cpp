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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        if(root->left==NULL && root->right==NULL)
            return root;
        
       // root->left=invertTree(root->left);
        //root->right=invertTree(root->right);
        struct TreeNode *temp;
        temp=invertTree(root->left);
        root->left=invertTree(root->right);
        root->right=temp;
        return root;
        
    }
};