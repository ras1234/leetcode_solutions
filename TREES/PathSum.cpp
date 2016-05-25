//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum. 
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
    bool auxHasPathSum(TreeNode * root,int currsum,int sum)
    {
        if(root==NULL)
            return false;
        if(root->left==NULL && root->right==NULL)
        {
            currsum+=root->val;
            if(currsum==sum)
                return true;
            else
                return false;
        }
        else
        {
            currsum+=root->val;
            int flag=false;
            flag=auxHasPathSum(root->left,currsum,sum);
            if(flag==false)
                return auxHasPathSum(root->right,currsum,sum);
            else
                return flag;
        }
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        int currsum=0;
        if(root==NULL)
            return false;
        if(root->left==NULL && root->right==NULL)
        {
            currsum+=root->val;
            if(currsum==sum)
                return true;
            else
                return false;
        }
        else 
        {
            currsum+=root->val;
            bool flag=false;
            flag=auxHasPathSum(root->left,currsum,sum);
            if(flag==false)
                return auxHasPathSum(root->right,currsum,sum);
            else
                return flag;
        }
    }
};