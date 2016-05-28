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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        if(root==NULL)
            return vec;
        stack<TreeNode*> st;
        while(1)
        {
           while(root)
           {
               if(root->right)
                    st.push(root->right);
                st.push(root);
                root=root->left;
           }
           root=st.top();
           st.pop();
          if(st.empty())
          {
            vec.push_back(root->val);
            break;
          }
            
           if(root->right!=NULL  && st.top()==root->right)
           {
                    st.pop();
                    st.push(root);
                    //st.push(root->right);
                    root=root->right;
           }
           else
           {
               vec.push_back(root->val);
               root=NULL;
           }
          if(st.empty())
                break;
          
        }
        return vec;
    }
};