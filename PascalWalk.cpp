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
    int w=t;
    while(t--)
    {
        int n,m,i,x,y,z,j;
        cin>>n;
        m=n;
        int ex=0;
        i=0;
        bool l=true;
        cout<<"Case #"<<(w-t)<<":"<<endl;
        if(n>30)
        {
            n=n-30;
            vector<pair<int,int> > v;
            
            
            for(i=0;i<=30;i++)
            {
                if(n&(1LL<<i))
                {
                    if(l)
                    {
                        x=i;
                        for(j=0;j<=x;j++)
                        {
                            cout<<i+1<<" "<<j+1<<endl;
                        }
                        l=false;
                    }
                    else
                    {
                        x=i;
                        for(j=x;j>=0;j--)
                        {
                            cout<<i+1<<" "<<j+1<<endl;
                        }
                        l=true;
                    }
                }
                else
                {
                    ex++;
                    if(l)
                    {
                        cout<<i+1<<" 1"<<endl;
                    }
                    else
                    {
                        cout<<i+1<<" "<<(i+1)<<endl;
                    }
                    
                }
            }
        }
        if(m<=30)
            n=m;
        else
        {
            n=30-ex;
        }
        
        for(j=0;j<n;j++)
        {
            if(l)
            cout<<i+1+j<<" 1"<<endl;
            else
            {
                cout<<i+1+j<<" "<<i+1+j<<endl;
            }
            
        }
    }
    return 0;
}
