class Solution {
public:
    long long mod =1e9+7;
    int numOfWays(int n) {
        long long dp1[n+1],dp2[n+1];
        dp1[0]=6;
        dp2[0]=6;
        for(int i=1;i<n;i++)
        {
            dp1[i]=(3*dp1[i-1]+2*dp2[i-1])%mod;
            dp2[i]=(2*dp1[i-1]+2*dp2[i-1])%mod;
        }
        int ans = (dp1[n-1]+dp2[n-1])%mod;
        return ans;
    }
};
