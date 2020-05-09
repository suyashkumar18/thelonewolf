//https://codeforces.com/contest/1131/problem/F
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
const int N= 150005 ;
const long long mod = 1.0e9+7;
int n,m,k;
int sz[N];
int root[N];
void init()
{
    for(int i=0;i<=n;i++)
    {
        root[i]=i;
        sz[i]=1;
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
    if(sz[rt1]>sz[rt2])
        swap(rt1,rt2);
    sz[rt2]+=sz[rt1];
    sz[rt1]=0;
    root[rt1]=root[rt2];
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
    int i,j,x,y,a,b;
    cin>>n;
    init();
    map<int,vector<int> > mp;
    for(i=1;i<=n;i++)
        mp[i].push_back(i);
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        a=rt(x);
        b=rt(y);
        //cout<<a<<" "<<b<<endl;
        if(a==b)
            continue;
        merge(x,y);
        if(rt(x)==a)
        {
            for(auto it:mp[b])
            {
                mp[a].push_back(it);
            }
        }
        else
        {
            for(auto it:mp[a])
            {
                mp[b].push_back(it);
            }
        }
    }
    x=rt(1);
    for(i=0;i<mp[x].size();i++)
    {
        cout<<mp[x][i]<<" ";
    }
    return 0;
}
