#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl "\n"
const int N= 100005 ;
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
        int a,b,c,i,x;
        cin>>a>>b>>c;
        vector<int> ar,br,cr;
        for(i=0;i<a;i++)
        {
            cin>>x;
            ar.push_back(x);
        }
        for(i=0;i<b;i++)
        {
            cin>>x;
            br.push_back(x);
        }
        for(i=0;i<c;i++)
        {
            cin>>x;
            cr.push_back(x);
        }
        sort(ar.begin(),ar.end());
        sort(br.begin(),br.end());
        sort(cr.begin(),cr.end());
        int minn= 5*1e18,ans;
        for(i=0;i<a;i++)
        {
            vector<int> v1,v2;
            int pos = lower_bound(br.begin(),br.end(),ar[i])-br.begin();
            int pos1 = (upper_bound(br.begin(),br.end(),ar[i])-br.begin());
            if(pos==pos1)
                pos1++;
            if((pos-1)>=0)
            {
                v1.push_back(br[pos-1]);
            }
            if(pos<b)
            {
                v1.push_back(br[pos]);
            }
            if(pos1<b)
            {
                v1.push_back(br[pos1]);
            }
            for(int j=0;j<v1.size();j++)
            {
                int pos = lower_bound(cr.begin(),cr.end(),v1[j])-cr.begin();
                int pos1 = (upper_bound(cr.begin(),cr.end(),v1[j])-cr.begin());
                if(pos==pos1)
                    pos1++;
                if((pos-1)>=0)
                {
                    v2.push_back(cr[pos-1]);
                }
                if(pos<c)
                {
                    v2.push_back(cr[pos]);
                }
                if(pos1<c)
                {
                    v2.push_back(cr[pos1]);
                }
                pos = lower_bound(cr.begin(),cr.end(),ar[i])-cr.begin();
                pos1 = (upper_bound(cr.begin(),cr.end(),ar[i])-cr.begin());
                if(pos==pos1)
                    pos1++;
                if((pos-1)>=0)
                {
                    v2.push_back(cr[pos-1]);
                }
                if(pos<c)
                {
                    v2.push_back(cr[pos]);
                }
                if(pos1<c)
                {
                    v2.push_back(cr[pos1]);
                }
            }
            for(int j=0;j<v1.size();j++)
            {
                for(int k=0;k<v2.size();k++)
                {
                    ans=(ar[i]-v1[j])*(ar[i]-v1[j]) + (ar[i]-v2[k])*(ar[i]-v2[k]) + (v1[j]-v2[k])*(v1[j]-v2[k]);
                    minn=min(minn,ans);
                }
            }
        }
        for(i=0;i<b;i++)
        {
            vector<int> v1,v2;
            int pos = lower_bound(ar.begin(),ar.end(),br[i])-ar.begin();
            int pos1 = (upper_bound(ar.begin(),ar.end(),br[i])-ar.begin());
            if(pos==pos1)
                pos1++;
            if((pos-1)>=0)
            {
                v1.push_back(ar[pos-1]);
            }
            if(pos<a)
            {
                v1.push_back(ar[pos]);
            }
            if(pos1<a)
            {
                v1.push_back(ar[pos1]);
            }
            for(int j=0;j<v1.size();j++)
            {
                int pos = lower_bound(cr.begin(),cr.end(),v1[j])-cr.begin();
                int pos1 = (upper_bound(cr.begin(),cr.end(),v1[j])-cr.begin());
                if(pos==pos1)
                    pos1++;
                if((pos-1)>=0)
                {
                    v2.push_back(cr[pos-1]);
                }
                if(pos<c)
                {
                    v2.push_back(cr[pos]);
                }
                if(pos1<c)
                {
                    v2.push_back(cr[pos1]);
                }
                pos = lower_bound(cr.begin(),cr.end(),br[i])-cr.begin();
                pos1 = (upper_bound(cr.begin(),cr.end(),br[i])-cr.begin());
                if(pos==pos1)
                    pos1++;
                if((pos-1)>=0)
                {
                    v2.push_back(cr[pos-1]);
                }
                if(pos<c)
                {
                    v2.push_back(cr[pos]);
                }
                if(pos1<c)
                {
                    v2.push_back(cr[pos1]);
                }
            }
            for(int j=0;j<v1.size();j++)
            {
                for(int k=0;k<v2.size();k++)
                {
                    ans=(br[i]-v1[j])*(br[i]-v1[j]) + (br[i]-v2[k])*(br[i]-v2[k]) + (v1[j]-v2[k])*(v1[j]-v2[k]);
                    minn=min(minn,ans);
                }
            }
        }
        for(i=0;i<c;i++)
        {
            vector<int> v1,v2;
            int pos = lower_bound(br.begin(),br.end(),cr[i])-br.begin();
            int pos1 = (upper_bound(br.begin(),br.end(),cr[i])-br.begin());
            if(pos==pos1)
                pos1++;
            if((pos-1)>=0)
            {
                v1.push_back(br[pos-1]);
            }
            if(pos<b)
            {
                v1.push_back(br[pos]);
            }
            if(pos1<b)
            {
                v1.push_back(br[pos1]);
            }
            for(int j=0;j<v1.size();j++)
            {
                int pos = lower_bound(ar.begin(),ar.end(),v1[j])-ar.begin();
                int pos1 = (upper_bound(ar.begin(),ar.end(),v1[j])-ar.begin());
                if(pos==pos1)
                    pos1++;
                if((pos-1)>=0)
                {
                    v2.push_back(ar[pos-1]);
                }
                if(pos<a)
                {
                    v2.push_back(ar[pos]);
                }
                if(pos1<a)
                {
                    v2.push_back(ar[pos1]);
                }
                pos = lower_bound(ar.begin(),ar.end(),cr[i])-ar.begin();
                pos1 = (upper_bound(ar.begin(),ar.end(),cr[i])-ar.begin());
                if(pos==pos1)
                    pos1++;
                if((pos-1)>=0)
                {
                    v2.push_back(ar[pos-1]);
                }
                if(pos<a)
                {
                    v2.push_back(ar[pos]);
                }
                if(pos1<a)
                {
                    v2.push_back(ar[pos1]);
                }
            }
            for(int j=0;j<v1.size();j++)
            {
                for(int k=0;k<v2.size();k++)
                {
                    ans=(cr[i]-v1[j])*(cr[i]-v1[j]) + (cr[i]-v2[k])*(cr[i]-v2[k]) + (v1[j]-v2[k])*(v1[j]-v2[k]);
                    minn=min(minn,ans);
                }
            }
        }
        cout<<minn<<endl;
    }
    return 0;
}
