//Given a binary tree, return all root-to-leaf paths. 

class Solution {
public:
    void auxBinaryTreePath(TreeNode *root,vector<string>& vec,string str)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            str+="->";
            str+=to_string(root->val);
            vec.push_back(str);
        }
        else
        {
            str+="->";
            str+=to_string(root->val);
            auxBinaryTreePath(root->left,vec,str);
            auxBinaryTreePath(root->right,vec,str);
        }
        return;
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> vec;
        string str="";
        if(root==NULL)
            return vec;
        if(root->left==NULL && root->right==NULL)
        {
            str+=to_string(root->val);
            vec.push_back(str);
            return vec;
        }
        else
        {
            str+=to_string(root->val);
            auxBinaryTreePath(root->left,vec,str);
            auxBinaryTreePath(root->right,vec,str);
        }
        return vec;
    }
};
