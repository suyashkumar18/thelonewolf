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
        int n,m,i,x,y,z;
        int a,b;
        cin>>n>>m;
        int k=m;
        int arr[n+1];
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int pref[2*k+5];
        memset(pref,0,sizeof(pref));
        set<int> s;
        map<int,int> mp;
        for(i=0;i<(n/2);i++)
        {
            s.insert(arr[i]+arr[n-i-1]);
            mp[arr[i]+arr[n-i-1]]++;
        }
        for(i=0;i<(n/2);i++)
        {
            x=max(arr[i],arr[n-i-1]);
            y=min(arr[i],arr[n-i-1]);
            pref[x+k+1]--;
            pref[y+1]++;
        }
        for(i=1;i<=(2*k);i++)
        {
            pref[i]+=pref[i-1];
        }
        s.insert(k+1);
        int minn=n;
        for(auto it:s)
        {
            auto p=it;
            minn=min(minn,n-mp[p]-pref[p]);
        }
        cout<<minn<<endl;
    }
    return 0;
}
