/*Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).*/


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
   void auxLevelOrderBottom(TreeNode *root,vector<vector<int>>& vec,int index)
   {
       if(root)
       {
           if(index+1 > vec.size())
                vec.resize(index+1);
           vec[index].push_back(root->val);
           auxLevelOrderBottom(root->left,vec,index+1);
           auxLevelOrderBottom(root->right,vec,index+1);
       }
   }


    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       vector<vector<int>> vec;
       if(root==NULL)
            return vec;
       auxLevelOrderBottom(root,vec,0);
       reverse(vec.begin(),vec.end());
       return vec;
     
        
    }
};