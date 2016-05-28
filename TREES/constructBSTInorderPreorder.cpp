// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
class Solution {
public:
    int preindex=0;
    
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
    
    TreeNode* auxBuildTree(vector<int>& preorder,vector<int>& inorder,int start,int end)
     {
      if(start>end)
            return NULL;
      struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
      root->val = preorder[preindex++];
      root->left = NULL;
      root->right = NULL;
      if(start==end)
      {
            return root;
      }
      int inIndex=Search(inorder,start,end,root->val);
      root->left=auxBuildTree(preorder,inorder,start,inIndex-1);
      root->right=auxBuildTree(preorder,inorder,inIndex+1,end);
      return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      if(preorder.empty() || inorder.empty())
            return NULL;
      else
        return auxBuildTree(preorder,inorder,0,inorder.size()-1);
    }
};