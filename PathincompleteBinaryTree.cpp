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
    int n,q,i,j;
    cin>>n>>q;
    int root = (n+1)/2;
    while(q--)
    {
        int m;
        string s;
        cin>>m;
        cin>>s;
        int l=s.length();
        for(i=0;i<l;i++)
        {
            if(s[i]=='U' && m!=root)
            {
                int x=m&(-m);
                int y=m+x;
                int z=m-x;
                if((y&(-y))==(2*x))
                    m=y;
                else
                {
                    m=z;
                }
                
            }
            else if(s[i]=='L')
            {
                int x= m&(-m);
                m-=(x/2);
            }
            else if(s[i]=='R')
            {
                int x= m&(-m);
                m+=(x/2);
            }
        }
        cout<<m<<endl;
    }
    return 0;
}
