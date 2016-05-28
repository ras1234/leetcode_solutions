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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> st;
        if(root==NULL)
            return vec;
        while(1)
        {
            while(root)
            {
                vec.push_back(root->val);
                st.push(root);
                root=root->left;
            }
            if(st.empty())
                break;
            root=st.top();
            st.pop();
            root=root->right;
        }
        return vec;
    }
};