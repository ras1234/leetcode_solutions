/* Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level). */

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
    void auxFunc(TreeNode *root, vector<vector<int>> &vec, int index)
    {
        if(root)
        {
            if(index+1>vec.size())
                vec.resize(index+1);
            vec[index].push_back(root->val);
            auxFunc(root->left,vec,index+1);
            auxFunc(root->right,vec,index+1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
    
        if(root==NULL)
            return vec;
            
        auxFunc(root,vec,0);
        return vec;
    }
};