/*  Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,3,2].   */

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        if(root==NULL)
            return vec;
        stack<TreeNode *> st;
        while(1)
        {
            while(root)
            {
                st.push(root);
                root=root->left;
            }
            if(st.empty())
                break;
            root=st.top();
            st.pop();
            vec.push_back(root->val);
            root=root->right;
        }
        return vec;
    }
};