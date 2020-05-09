//https://codeforces.com/contest/825/problem/E
//Topological Labelling Concept
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
const int N= 100005 ;
const long long mod = 1.0e9+7;
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
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[y].push_back(x);
        
    }
    int vis[n+1];
    memset(vis,0,sizeof(vis));
    int indeg[n+1];
    memset(indeg,0,sizeof(indeg));
    for(i=1;i<=n;i++)
    {
        for(auto it:adj[i])
        {
            indeg[it]++;
        }
    }
    priority_queue<int> pq;
    for(i=1;i<=n;i++)
    {
        if(indeg[i]==0)
            pq.push(i);
    }
    vector<int> v(n+1,0);
    int l=n;
    while(pq.size()>0)
    {
        int p= pq.top();
        v[p]=l--;
        pq.pop();
        for(auto it:adj[p])
        {
            indeg[it]--;
            if(indeg[it]==0)
            {
                pq.push(it);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<v[i+1]<<" ";
    }
    return 0;
}
