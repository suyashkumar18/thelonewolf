#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
const int N= 200005 ;
int dp[2005][2005][11];
int cnt[2005][11];
int n;
int solve(int pos,int k,int num)
{
    int i;
    if(pos==n)
    {
        if(k==0)
        {
            return dp[pos][k][num]=1;
        }
        return dp[pos][k][num]=0;
    }
    if(k<0)
        return 0;
    if(dp[pos][k][num]!=-1)
        return dp[pos][k][num];
    int ans=0;
    for(i=9;i>=0;i--)
    {
        if(cnt[pos][i]!=-1 && cnt[pos][i]<=k)
            ans|=solve(pos+1,k-cnt[pos][i],i);
    }
    dp[pos][k][num]=ans;
    return ans;
}
string answer(int pos,int k,int num)
{
    int i;
    string ans="";
    if(pos==n)
        return ans;
    for(i=9;i>=0;i--)
    {
        if(cnt[pos][i]!=-1 && k>=cnt[pos][i] && dp[pos+1][k-cnt[pos][i]][i]==1)
        {
            //cout<<dp[pos][k-cnt[pos][i]][i]<<endl;
            ans+=(char)(i+48);
            ans+=answer(pos+1,k-cnt[pos][i],i);
            return ans;
        }
    }
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
    vector<string> digits = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
    int k,i,j;
    cin>>n>>k;
    string s[n+1];
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<10;j++)
        {
            int cn=0;
            for(int l=0;l<7;l++)
            {
                if(s[i][l]=='0' && digits[j][l]=='1')
                    cn++;
                else if(s[i][l]=='1' && digits[j][l]=='0')
                {
                    cn=-1;
                    break;
                }
            }
            cnt[i][j]=cn;
        }
    }
    memset(dp,-1,sizeof(dp));
    if(solve(0,k,0)==0)
        cout<<"-1"<<endl;
    else
    {
        cout<<answer(0,k,0)<<endl;
    }
    return 0;
}
