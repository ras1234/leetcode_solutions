/* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center). */

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
    
    bool auxIsSymmetric(TreeNode *root1,TreeNode *root2)
    {
       if(root1==NULL && root2==NULL)
            return true;
        if((root1==NULL && root2!=NULL)||(root1!=NULL && root2==NULL))
            return false;
        // if((root1->left==NULL && root2->left==NULL)||(root1->right==NULL && root2->right==NULL) && (root1->val==root2->val))
        //     return true;
        if(root1->val==root2->val)
        {
            return (auxIsSymmetric(root1->left,root2->right) && auxIsSymmetric(root1->right,root2->left));
        }
        else 
            return false;
            
    }
    
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->left==NULL && root->right==NULL)
            return true;
       else
       {
           return auxIsSymmetric(root->left,root->right);
       }
       return false;
    }
};
