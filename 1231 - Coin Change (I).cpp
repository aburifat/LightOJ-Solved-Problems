#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll mod=100000007;

ll val[55];
ll ct[55];
ll n,k;

ll dp[1010][55][25];

ll ctdp(ll res,ll idx,ll thisct)
{
    ll coin=val[idx];
    if(res==0)return 1;
    if(res<0||idx<0)return 0;
    if(dp[res][idx][thisct]!=-1)return dp[res][idx][thisct];
    ll tmp=0;
    for(ll i=0;i<=thisct;i++){
        tmp=(tmp+ctdp(res-(i*coin),idx-1,ct[idx-1]))%mod;
    }
    return dp[res][idx][thisct]=tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        for(ll i=0;i<1010;i++){
            for(ll j=0;j<55;j++){
                for(ll k=0;k<25;k++)dp[i][j][k]=-1;
            }
        }
        cin>>n>>k;
        for(ll i=0;i<n;i++)cin>>val[i];
        for(ll i=0;i<n;i++)cin>>ct[i];
        ll ans=ctdp(k,n-1,ct[n-1]);
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
