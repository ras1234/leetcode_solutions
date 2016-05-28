/*  Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.  

 For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL


*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)
            return;
        queue<TreeLinkNode*> q;
        struct TreeLinkNode *temp;
        q.push(root);
        q.push(NULL);
        root->next=NULL;
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            if(temp && !q.empty())
            {
                if(q.front()!=NULL)
                {
                    temp->next=q.front();
                }
                else if(q.front()==NULL)
                {
                    temp->next=NULL;
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            
            if(temp==NULL && !q.empty())
            {
                q.push(temp);            
            }
        }
    }
};

