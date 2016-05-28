/*  Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
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
    void auxZigZagLevelOrder(TreeNode *root,vector<vector<int>> &vec,int index)
    {
        if(root)
        {
            if(index+1 > vec.size())
            {
                vec.resize(index+1);
            }
            vec[index].push_back(root->val);
            auxZigZagLevelOrder(root->left,vec,index+1);
            auxZigZagLevelOrder(root->right,vec,index+1);
        }
        return;
    }
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> vec;
       if(root==NULL)
            return vec;
        auxZigZagLevelOrder(root,vec,0);
        for(int i=0;i<vec.size();i++)
        {
            if(i%2==1)
                reverse(vec[i].begin(),vec[i].end());
        }
        return vec;
    }
};