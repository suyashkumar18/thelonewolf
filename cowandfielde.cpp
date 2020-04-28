#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
const int N= 200005 ;
const long long mod = 1.0e9+7;
int n,m,k;
vector<int> adj[N];
int dist[2][N];
void bfs(int* dis,int node)
{
    fill(dis,dis+n+1,1e18);
    queue<int> q;
    q.push(node);
    dis[node]=0;
    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        for(auto it: adj[p])
        {
            if(dis[it]>(dis[p]+1))
            {
                dis[it]=dis[p]+1;
                q.push(it);
            }
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
    cin>>n>>m>>k;
    int ar[k+1];
    int i,j,x,y;
    for(i=0;i<k;i++)
    {
        cin>>ar[i];
    }
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(dist[0],1);
    bfs(dist[1],n);
    vector<pair<int,int> > v;
    for(i=0;i<k;i++)
    {
        v.push_back({dist[0][ar[i]]-dist[1][ar[i]],ar[i]});
    }
    sort(v.rbegin(),v.rend());
    int ans=0,maxx=-1e18;
    for(auto it: v)
    {
        auto a=it.second;
        ans=max(ans,maxx+dist[0][a]);
        maxx=max(maxx,dist[1][a]);
    }
    cout<<min(dist[0][n],ans+1)<<endl;
    return 0;
}
