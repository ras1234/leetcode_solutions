/* Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.  */

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        struct TreeNode *left,*right;
        if(root==NULL)
            return root;
        if(root==p || root==q)
            return root;
        left=lowestCommonAncestor(root->left,p,q);
        right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL && right!=NULL)
            return root;
        if(left==NULL)
            return right;
        else if(right==NULL)
            return left;
        return root;
            
    }
};