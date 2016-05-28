/*   Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
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
    void auxPathSum(TreeNode *root,vector<vector<int>>&vec,vector<int> subvec,int currsum,int sum)
    {
       if(root==NULL)
        return;
       if(root->left==NULL && root->right==NULL)
       {
           currsum+=root->val;
           subvec.push_back(root->val);
           if(currsum==sum)
                vec.push_back(subvec);
            return ;
       }
       else
       {
           currsum+=root->val;
           subvec.push_back(root->val);
           auxPathSum(root->left,vec,subvec,currsum,sum);
           auxPathSum(root->right,vec,subvec,currsum,sum);
       }
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> vec;
        vector<int> subvec;
        if(root==NULL)
            return vec;
        int currsum=0;
        if(root->left==NULL && root->right==NULL)
        {
            currsum+=root->val;
            subvec.push_back(root->val);
            if(currsum==sum)
                vec.push_back(subvec);
            return vec;
        }
        else
        {
            currsum+=root->val;
            subvec.push_back(root->val);
            auxPathSum(root->left,vec,subvec,currsum,sum);
            auxPathSum(root->right,vec,subvec,currsum,sum);
        }
        return vec;
        
    }
};