#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin>>t;
    ll n;
    for(ll T=1;T<=t;T++){
        cin>>n;
        ll cost[n+5][n+5];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cin>>cost[i][j];
            }
        }
        ll len=powl(2,n);
        ll dp[len+5];
        for(ll i=0;i<=len;i++)dp[i]=LONG_MAX;
        dp[0]=0;
        for(ll mask=0;mask<len;mask++){
            ll x=__builtin_popcount(mask);
            for(ll j=0;j<n;j++){
                if((mask&(1<<j))==0){
                    dp[mask|(1<<j)]=min(dp[mask|(1<<j)],dp[mask]-cost[x][j]);
                }
            }
        }
        cout<<"Case "<<T<<": ";
        cout<<-dp[len-1]<<"\n";
    }
    return 0;
}