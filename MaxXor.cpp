//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
class Solution {
public:
    struct Node{
        Node* child[2];
    };
    Node* init()
    {
        Node* node = new Node();
        node->child[0]=NULL;
        node->child[1]=NULL;
        return node;
    }
    void insert(Node* node,int nums)
    {
        for(int i=30;i>=0;i--)
        {
            if(nums&(1LL<<i))
            {
                if(node->child[1]==NULL)
                    node->child[1]=init();
                node=node->child[1];
            }
            else
            {
                if(node->child[0]==NULL)
                    node->child[0]=init();
                node=node->child[0];
            }
        }
    }
    int solve(Node* node,int nums)
    {
        int ans=0;
        for(int i=30;i>=0;i--)
        {
           if(nums&(1LL<<i))
            {
               if(node->child[0]==NULL)
                    node=node->child[1];
               else
                   ans+=(1LL<<i),node=node->child[0];
            }
            else
            {
                if(node->child[1]==NULL)
                     node=node->child[0];
                else
                    ans+=(1LL<<i),node=node->child[1];
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        Node* root=init();
        for(int i=0;i<nums.size();i++)
        {
            insert(root,nums[i]);
        }
        int maxx=0;
        for(int i=0;i<nums.size();i++)
        {
            maxx=max(maxx,solve(root,nums[i]));
        }
        return maxx;
    }
};
