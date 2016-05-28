/* Given a binary search tree, write a function kthSmallest to find the kth smallest element in it. */

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
    vector<int> inorder;
    void inOrderTraversal(TreeNode *root)
    {
            if(root==NULL)
                return ;
            else
            {
                inOrderTraversal(root->left);
                inorder.push_back(root->val);
                inOrderTraversal(root->right);
            }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        inOrderTraversal(root);
        return inorder[k-1];
    
    }
};