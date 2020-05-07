//https://codeforces.com/contest/449/problem/B
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
const int MAX= 100005 ;
const long long mod = 1e12;
int cnt;
struct edge{
    int v,w,f;
};
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int n,m,k;
    cin>>n>>m>>k;
    vector<edge> adjlist[n+1];
    int i,j,x,y,z;
    for(i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        adjlist[x].push_back({y,z,0});
        adjlist[y].push_back({x,z,0});
    }
    vector<pair<int,int> > q;
    for(i=0;i<k;i++)
    {
        cin>>y>>z;
        q.push_back({y,z});
        x=1;
        adjlist[x].push_back({y,z,1});
        adjlist[y].push_back({x,z,1});
    }
    vector<int> dist(n+5,0);
    for(i=1;i<=n;i++)
    {
        dist[i]=mod;
    }
    set<pair<int,int> > s;
    s.insert({0,1});
    dist[1]=0;
    vector<int> f(n+1,0);
    while(s.size()>0)
    {
        auto p=*(s.begin());
        s.erase(p);
        for(auto it: adjlist[p.second])
        {
            if(dist[it.v]>(dist[p.second]+it.w) || (dist[it.v]==(dist[p.second]+it.w) && it.f==0))
            {
                s.erase({dist[it.v],it.v});
                dist[it.v]=(dist[p.second]+it.w);
                s.insert({dist[it.v],it.v});
                f[it.v] = it.f;
            }
        }
    }
    int cnt=0;
    int mp[100005]={0};
    for(i=0;i<k;i++)
    {
        y=q[i].first;
        x=1;
        z=q[i].second;
        if(f[y]==0 || mp[y]>0)
        {
            cnt++;
        }
        mp[y]++;
    }
    cout<<cnt<<endl;
    return 0;
}
