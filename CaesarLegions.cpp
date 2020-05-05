//https://codeforces.com/contest/118/problem/D
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
const int MAX= 100005 ;
const long long mod = 1.0e8;
int n1,n2,k1,k2;
int dp[105][105][2];
int solve(int a,int b,int flag)
{
    if(a==0 && b==0)
        return 1;
    if(a<0 || b<0)
        return 0;
    if(dp[a][b][flag]!=-1)
        return dp[a][b][flag];
    dp[a][b][flag]=0;
    if(flag==0 && a>0)
    {
        for(int i=1;i<=k1;i++)
        {
            dp[a][b][flag]+=solve(a-i,b,1);
            dp[a][b][flag]%=mod;
        }
    }
    else if(flag==1 && b>0)
    {
        for(int i=1;i<=k2;i++)
        {
            dp[a][b][flag]+=solve(a,b-i,0);
            dp[a][b][flag]%=mod;
        }
    }
    else
    {
        return 0;
    }
    return dp[a][b][flag];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int i;
    cin>>n1>>n2>>k1>>k2;
    memset(dp,-1,sizeof(dp));
    cout<<(solve(n1,n2,0)+solve(n1,n2,1))%mod<<endl;
    return 0;
}
