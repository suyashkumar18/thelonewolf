#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
const int N= 100005 ;
const long long mod = 1.0e9+7;
vector<int> adj[N+1];
vector<int> lvl;
int n,mn,mx,x;
int sum;
void dfs(int node,int parent,int level)
{
    if(adj[node].size()==1)
    {
        lvl.push_back(level%2);
        sum+=lvl[lvl.size()-1];
    }
    for(auto it: adj[node])
    {
        if(it!=parent)
            dfs(it,node,level+1);
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
    cin>>n;
    int i,x,y,m=0;
    for(i=0;i<(n-1);i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    } 
    map<int,int> mp;
    for(i=1;i<=n;i++)
    {
        if(adj[i].size()==1)
        {
            m++;
            mp[adj[i][0]]++;
        }
    }
    mn=1;
    dfs(1,0,0);
    mx=n-1-m+mp.size();
    if(sum==0 || sum==lvl.size())
        mn=1;
    else
    {
        mn=3;
    }
    
    cout<<mn<<" "<<mx<<endl;
    return 0;
}
