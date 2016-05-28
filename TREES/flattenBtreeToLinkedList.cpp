/*  Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
    void auxFlatten(TreeNode* root,TreeNode* &next)
    {
        if(root)
        {
            auxFlatten(root->right,next);
            auxFlatten(root->left,next);
            root->right=next;
            root->left=NULL;
            next=root;
        }
        return;
    }
    
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        struct TreeNode *next=NULL;
        auxFlatten(root,next);
        return;
        
    }
};