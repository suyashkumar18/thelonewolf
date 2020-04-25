#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
const int MAX= 100005 ;
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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i,j,x,y,z;
        int a[3],b,c,d;
        cin>>n>>m>>a[0]>>a[1]>>a[2];
        vector<int> v;
        for(i=0;i<m;i++)
        {
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int pref[m+1];
        pref[0]=0;
        for(i=0;i<m;i++)
        {
            pref[i+1]=pref[i]+v[i];
        }
        vector<int> adj[n+1];
        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int dist[3][n+1];
        for(i=0;i<3;i++)
        {
            for(j=0;j<=n;j++)
            {
                dist[i][j]=1e18;
            }
        }
        for(i=0;i<3;i++)
        {
            queue<int> q;
            q.push(a[i]);
            dist[i][a[i]]=0;
            while(!q.empty())
            {
                int cur = q.front();
                q.pop();
                for(auto it: adj[cur])
                {
                    if(dist[i][it]>(dist[i][cur]+1))
                    {
                        dist[i][it]=dist[i][cur]+1;
                        q.push(it);
                    }
                }
            }
        }
        int ans=1e18;
        for(i=1;i<=n;i++)
        {
            if((dist[0][i]+dist[1][i]+dist[2][i])>m)
                continue;
            ans=min(ans,pref[dist[1][i]]+pref[dist[0][i]+dist[1][i]+dist[2][i]]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
