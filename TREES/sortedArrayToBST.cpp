/*  Given an array where elements are sorted in ascending order, convert it to a height balanced BST. */

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
    struct TreeNode *auxSortedArrayToBST(vector<int>& nums,int start,int end)
    {
        if(start>end)
            return NULL;
        struct TreeNode *root=(struct TreeNode *)malloc(sizeof(struct TreeNode));
       
        if(start==end)
        {
            root->val=nums[start];
            root->left=NULL;
            root->right=NULL;   
        }
        else
        { 
            int mid=((start+end)/2);
            root->val=nums[mid];
            root->left=auxSortedArrayToBST(nums,start,mid-1);
            root->right=auxSortedArrayToBST(nums,mid+1,end);
        }
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        if(nums.size()==1)
        {
            struct TreeNode *root=new TreeNode(nums[0]); 
            return root;
        }
        int start=0,end=nums.size()-1;
        return auxSortedArrayToBST(nums,0,nums.size()-1);
        
    }
};