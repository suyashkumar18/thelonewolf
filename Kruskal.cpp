//https://codeforces.com/contest/1095/problem/F
#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
const int MAX= 100005 ;
const long long mod = 1.0e9+7;
const int N=4e5+5;
vector<pair<ll, pair<ll,ll> > > edge;
pair<int,int> a[N];
int size[N];
int root[N];
int n,m;
void init()
{
    for(int i=0;i<=n;i++)
    {
        root[i]=i;
        size[i]=1;
    }
}
int rt(int node)
{
    while(node!=root[node])
    {
        root[node]=root[root[node]];
        node=root[node];
    }
    return node;
}
void merge(int u, int v)
{
    int rt1=rt(u), rt2=rt(v);
    if(rt1==rt2)
        return;
    if(size[rt1]>size[rt2])
        swap(rt1,rt2);
    size[rt2]+=size[rt1];
    size[rt1]=0;
    root[rt1]=root[rt2];
}
int kruskal()
{
    init();
    int cost=0,x,y;
    sort(edge.begin(),edge.end() );
    for(int i=0;i<m;i++)
    {
        x=edge[i].second.first;
        y=edge[i].second.second;
        if(rt(x)!=rt(y))
        {
            merge(x,y);
            cost+=edge[i].first;
        }
    }
    return cost;
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
    int i,x,y,z;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a,a+n);
    for(i=0;i<m;i++)
    {
        cin>>x>>y>>z;
        edge.push_back({z,{x,y}});
    }
    int pos=a[0].second;
    for(i=0;i<n;i++)
    {
        if(a[i].second != pos)
        {
            edge.push_back({(a[0].first+a[i].first),{a[0].second,a[i].second}});
        }
    }
    m+=n-1;
    cout<<kruskal()<<endl;
    return 0;
}
