#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
const int MAX= 100005 ;
const long long mod = 1.0e9+7;
bool comp(string s1,string s2)
{
    return s1.length()>s2.length();
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int w=t;
    while(t--)
    {
        int n,m,i,j,k,x,y,z;
        cin>>n;
        string s[n+1];
        string pref[n+1],suff[n+1];
        for(i=0;i<n;i++)
        {
            cin>>s[i];
            x=s[i].length();
            j=0;
            while(j<x && s[i][j]!='*')
            {
                pref[i].push_back(s[i][j]);
                j++;
            }
            j=x-1;
            while(j>=0 && s[i][j]!='*')
            {
                suff[i].push_back(s[i][j]);
                j--;
            }
            if(suff[i].size()>0)
            reverse(suff[i].begin(),suff[i].end());
        }
        cout<<"Case #"<<(w-t)<<":"<<" ";
        sort(pref,pref+n,comp);
        sort(suff,suff+n,comp);
        /*for(i=0;i<n;i++)
        {
            cout<<pref[i]<<" "<<suff[i]<<endl;
        }*/
        string ex="";
        int f=0;
        for(i=1;i<n;i++)
        {
            if(pref[0].find(pref[i])!=0)
            {
                f=1;
                cout<<"*"<<endl;
                break;
            }
        }
        if(!f)
        {
            reverse(suff[0].begin(),suff[0].end());
            for(i=1;i<n;i++)
            {
                reverse(suff[i].begin(),suff[i].end());
                if(suff[0].find(suff[i])!=0)
                {
                    f=1;
                    cout<<"*"<<endl;
                    break;
                }
            }
        }
        if(!f)
        {
            reverse(suff[0].begin(),suff[0].end());
            for(i=0;i<n;i++)
            {
                j=0;
                while(j<x && s[i][j]!='*')
                {
                    j++;
                }
                k=s[i].length()-1;
                while(k>=0 && s[i][k]!='*')
                {
                    k--;
                }    
                for(int l=j+1;l<k;l++)
                {
                    if(s[i][l]!='*')
                        ex.push_back(s[i][l]);
                }
            }
            cout<<pref[0]<<ex<<suff[0]<<endl;
        }
    }
    return 0;
}
