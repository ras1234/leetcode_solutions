/*  Given inorder and postorder traversal of a tree, construct the binary tree. */

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
     int Search(vector<int>& inorder,int start,int end,int data)
    {
        int index=0;
        for(int i=start;i<=end;i++)
        {
            if(inorder[i]==data)
                index=i;
        }
        return index;
    }
    TreeNode* auxBuildTree(vector<int>& postorder,vector<int>& inorder,int start,int end)
     {
      if(start>end)
            return NULL;
      struct TreeNode *root=new TreeNode(postorder.back());
      //postorder.resize(postorder.size()-1);
      postorder.erase(postorder.end()-1);
      if(start==end)
      {
            return root;
      }
      int inIndex=Search(inorder,start,end,root->val);
      root->right=auxBuildTree(postorder,inorder,inIndex+1,end);
      root->left=auxBuildTree(postorder,inorder,start,inIndex-1);
      
      return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      if(postorder.empty() || inorder.empty())
            return NULL;
      else
      {
        return auxBuildTree(postorder,inorder,0,inorder.size()-1);
      }
    }
};