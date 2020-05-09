//https://codeforces.com/contest/770/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
const int N= 100005 ;
const long long mod = 1.0e9+7;
int n,m,k;
int ar[N+1];
vector<int> adj[N+1];
int vis[N+1];
vector<int> v;
int cycle;
void dfs(int node)
{
    vis[node]=1;
    for(auto it: adj[node])
    {
        if(vis[it]==0)
            dfs(it);
        else if(vis[it]==1)
        {
            cycle=1;
            return;
        }
    }
    vis[node]=2;
    v.push_back(node);
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
    int i,j,x,y;
    cin>>n>>k;
    for(i=0;i<k;i++)
    {
        cin>>ar[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>m;
        for(j=0;j<m;j++)
        {
            cin>>x;
            adj[i].push_back(x);
        }
    }
    memset(vis,0,sizeof(vis));
    cycle=0;
    for(i=0;i<k;i++)
    {
        if(vis[ar[i]]==0 && cycle==0) 
            dfs(ar[i]);
    }
    if(cycle==1)
        cout<<"-1"<<endl;
    else
    {
        cout<<v.size()<<endl;
        for(i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
    }
    
    return 0;
}
