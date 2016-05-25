/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.  */

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
    
    int Height(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        else
        {
            return 1+max(Height(root->left),Height(root->right));
        }
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->left==NULL && root->right==NULL)
            return true;
        else
        {
            int leftHeight=Height(root->left);
            int rightHeight=Height(root->right);
            int diff=(leftHeight)-(rightHeight);
            if(diff<0)
                diff=-diff;
            if(diff==0 || diff==1)
            {
                return (isBalanced(root->left) && isBalanced(root->right));
            }
            else
                return false;
        }
    }
};
