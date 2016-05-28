/* Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom. */

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
    void auxRightSideView(TreeNode *root,vector<int>& vec,int index)
    {
        if(root==NULL)
            return;
        if(root)
        {
            if(index+1>vec.size())
            {
                //vec.resize(index+1);
                vec.push_back(root->val);
            }
            auxRightSideView(root->right,vec,index+1);
            auxRightSideView(root->left,vec,index+1);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
     vector<int> vec;
     if(root==NULL)
        return vec;
     auxRightSideView(root,vec,0);
     return vec;
        
     }
};