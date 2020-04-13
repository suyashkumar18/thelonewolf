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
        int n,k,i,j;
        cin>>n;
        int arr[n+1];
        set<int> s;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            s.insert(arr[i]);
        }
        vector<int> v;
        for(auto it: s)
            v.push_back(it);
        int m=v.size(),a,b,maxx=0,l=0,r=0,cl=0;
        for(i=0;i<m;i++)
        {
            a=v[i];
            l=0;
            r=n-1;
            cl=0;
            while(l<=r)
            {
                if(arr[l]==a && arr[r]==a)
                {
                    if(l==r)
                        cl++;
                    else
                    {
                        cl+=2;
                    }
                    
                    map<int,int> mp;
                    for(j=l+1;j<r;j++)
                    {
                        mp[arr[j]]++;
                    }
                    int mx=0;
                    for(auto it:mp)
                    {
                        mx=max(mx,it.second);
                    }
                    maxx=max(maxx,cl+mx);
                    l++;
                    r--;
                }
                else if(arr[l]==a)
                {    
                    r--;
                }
                else if(arr[r]==a)
                {
                    l++;
                }
                else{
                    l++;
                    r--;
                }
            }
        }
        cout<<maxx<<endl;
    }
    return 0;
}
