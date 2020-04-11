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
        cin>>n;
        int a[n+1],b[n+1];
        for(i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
        }
        int diff[n+1];
        memset(diff,0,sizeof(diff));
        for(i=1;i<n;i++)
        {
            diff[i]=max(0LL,a[i]-b[i-1]);
        }
        diff[0]=max(0LL,a[0]-b[n-1]);
        int pref[n+1];
        pref[0]=0;
        for(i=0;i<n;i++)
        {
            pref[i+1]=pref[i]+diff[i];
        }
        int minn= 1e18,ans;
        for(i=0;i<n;i++)
        {
            ans=a[i]+pref[n]-pref[i+1]+pref[i];
            minn=min(minn,ans);
        }
        cout<<minn<<endl;
    }
    return 0;
}
