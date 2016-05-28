/*  Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.  */

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
    void auxSumNumbers(TreeNode *root,vector<int>&vec,int currsum)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            currsum=currsum*10+root->val;
            //subvec.push_back(currsum);
            vec.push_back(currsum);
        }
        else
        {
            currsum=currsum*10+root->val;
          //  subvec.push_back(currsum);
            auxSumNumbers(root->left,vec,currsum);
            auxSumNumbers(root->right,vec,currsum);
        }
        return;
    }
    
    
    int sumNumbers(TreeNode* root) {
        vector<int> vec;
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
        {
            return (root->val);
        }
        else
        {
            int currsum=0;
            currsum+=root->val;
           // subvec.push_back(root->val);
            auxSumNumbers(root->left,vec,currsum);
            auxSumNumbers(root->right,vec,currsum);
        }
        int sum=0;
        for(int i=0;i<vec.size();i++)
            sum+=vec[i];
        return sum;
        
    }
};