#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>mp;
vector<ll>v;
ll len,n,w,k;
ll dp[110][110];
ll ctdp(ll idx,ll take)
{
    if(idx>=len||take<=0)return 0;
    ll mx=v[idx]+w;
    if(dp[idx][take]!=-1)return dp[idx][take];
    else
    {
        ll tmp=0;
        ll newidx=idx;
        for(ll i=idx; i<len; i++)
        {
            if(v[i]>mx)break;
            tmp+=mp[v[i]];
            newidx=i;
        }
        newidx++;
        dp[idx][take]=max(ctdp(idx+1,take),tmp+ctdp(newidx,take-1));
        return dp[idx][take];
    }

}

int main()
{
    ll t;
    cin>>t;
    for(ll T=1; T<=t; T++)
    {
        cin>>n>>w>>k;
        for(ll i=0;i<110;i++){
            for(ll j=0;j<110;j++)dp[i][j]=-1;
        }
        mp.clear();
        v.clear();
        for(ll i=0; i<n; i++)
        {
            ll x,y;
            cin>>x>>y;
            if(!mp[y])v.push_back(y);
            mp[y]++;
        }
        sort(v.begin(),v.end());
        len=v.size();
        ll ans=ctdp(0,k);
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
