/*   Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
 */

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
    bool auxIsValidBST(TreeNode *root,int lb,int ub)
    {
        if(root==NULL)
            return true;
        if(root->left==NULL && root->right==NULL )
        {
            if(root->val >=lb && root->val <=ub)
                return true;
            else
                return false;
        }
        if((root->val==INT_MIN && root->left) || (root->val==INT_MAX && root->right) )
            return false;
        else if(root->val >=lb && root->val <=ub)
        {
            return(auxIsValidBST(root->left,lb,(root->val)-1) && auxIsValidBST(root->right,(root->val)+1,ub));
        }
        return false;
        
    }
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->left==NULL && root->right==NULL)
        {
             return true;
        }
        else
        {
            return auxIsValidBST(root,INT_MIN,INT_MAX);
        }
    }
};