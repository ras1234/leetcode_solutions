/*  Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.  */

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
    struct TreeNode *auxRecoverTree(TreeNode* root,TreeNode* &first,TreeNode* &second,TreeNode* &prev)
    {
        if(root)
        {
            auxRecoverTree(root->left,first,second,prev);
            if(prev!=NULL && root->val < prev->val)
            {
                if(first)
                {
                    second=root;
                }
                else
                {
                    first=prev;
                    second=root;
                }
            }
            prev=root;
            auxRecoverTree(root->right,first,second,prev);
        }
        return root;
    }
    
    void recoverTree(TreeNode* root) {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
            return ;
        struct TreeNode *first=NULL,*second=NULL,*prev=NULL;
        auxRecoverTree(root,first,second,prev);
        if(first && second)
            swap(first->val,second->val);
        return ;
    }
};