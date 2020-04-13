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
    TreeNode* addtree(TreeNode* root,int v)
    {
        if(root==NULL)
            return root;
        TreeNode* r=new TreeNode((root->val)+v);
        r->left=addtree(root->left,v);
        r->right=addtree(root->right,v);
        return r;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> v[n+1];
        if(n==0)
            return v[0];
        TreeNode* p =new TreeNode(1);
        v[1].push_back(p);
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                if(v[j-1].size()==0)
                {
                    for(int l=1;l<=v[i-j].size();l++)
                    {
                        TreeNode* p= new TreeNode(j);
                        p->left=NULL;
                        p->right=addtree(v[i-j][l-1],j);
                        v[i].push_back(p);
                    }    
                }
                else if(v[i-j].size()==0)
                {
                    for(int l=1;l<=v[j-1].size();l++)
                    {
                        TreeNode* p= new TreeNode(j);
                        p->left=addtree(v[j-1][l-1],0);
                        p->right=NULL;
                        v[i].push_back(p);
                    }
                }
                for(int k=1;k<=v[j-1].size();k++)
                {
                    for(int l=1;l<=v[i-j].size();l++)
                    {
                        TreeNode* p= new TreeNode(j);
                        p->left=addtree(v[j-1][k-1],0);
                        p->right=addtree(v[i-j][l-1],j);
                        v[i].push_back(p);
                    }
                }
            }
        }
        return v[n];
    }
};
