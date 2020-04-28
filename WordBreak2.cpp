class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> mp;
        int n;
        n= s.length();
        vector<bool> dp(n+1,false);
        vector<string> dp1[n+1];
        int i,j;
        for(i=0;i<wordDict.size();i++)
        {
            mp.insert(wordDict[i]);
        }
        string t="";
        vector<string> v;
        for(i=0;i<n;i++)
        {
            t="";
            if(i==0 || dp[i-1])
            {
                for(j=1;j<=(n-i);j++)
                {
                    t.push_back(s[i+j-1]);
                    if(mp.find(t)!=mp.end())
                    {
                        dp[i+j-1]=true;
                    }
                    if(dp[n-1])
                        break;
                }
                if(dp[n-1])
                        break;
            }
        }
        if(!dp[n-1])
            return v;
        for(i=0;i<n;i++)
        {
            t="";
            if(i==0)
            {
                for(j=1;j<=(n-i);j++)
                {
                    t.push_back(s[i+j-1]);
                    if(mp.find(t)!=mp.end())
                    {
                        dp[i+j-1]=true;
                        dp1[i+j-1].push_back(t);
                    }
                }
            }
            else if(dp[i-1])
            {
                for(j=1;j<=(n-i);j++)
                {
                    t.push_back(s[i+j-1]);
                    if(mp.find(t)!=mp.end())
                    {
                        
                        dp[i+j-1]=true;
                        int x=dp1[i+j-1].size();
                        for(int k=0;k<dp1[i-1].size();k++)
                        {
                            dp1[i+j-1].push_back(dp1[i-1][k]);
                        }
                        for(int k=x;k<dp1[i+j-1].size();k++)
                        {
                            if(dp1[i+j-1][k].length()>0)
                                dp1[i+j-1][k].push_back(' ');
                            dp1[i+j-1][k]+=t;
                        }
                    }
                }
            }
        }
        return dp1[n-1];
    }
};
