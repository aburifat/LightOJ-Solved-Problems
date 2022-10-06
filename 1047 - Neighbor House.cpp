#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX=LONG_MAX;

ll cst[23][5];
ll dp[23][5];
ll ctdp(ll idx,ll pre)
{
    if(idx==0)return 0;
    if(dp[idx][pre]!=MX)return dp[idx][pre];
    for(ll i=1;i<=3;i++){
        if(i==pre)continue;
        dp[idx][pre]=min(dp[idx][pre],ctdp(idx-1,i)+cst[idx][i]);
    }
    return dp[idx][pre];
}

int main()
{
    ll t;
    cin>>t;
    ll n;
    for(ll T=1;T<=t;T++){
        for(ll i=0;i<23;i++){
            for(ll j=0;j<5;j++)dp[i][j]=MX;
        }
        cin>>n;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=3;j++){
                cin>>cst[i][j];
            }
        }
        ll ans=ctdp(n,0);
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
