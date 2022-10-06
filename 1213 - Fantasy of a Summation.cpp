#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binpow(ll base, ll power, ll mod)
{
    base%=mod;
    ll result=1;
    while(power>0){
        if(power&1)result=(result*base)%mod;
        base=(base*base)%mod;
        power>>=1;
    }
    return result;
}

int main()
{
    ll t;
    cin>>t;
    ll n, k, mod;
    for(ll T=1; T<=t; T++){
        cin>>n>>k>>mod;
        ll sum=0, tmp;
        for(ll i=0;i<n;i++){
            cin>>tmp;
            sum=((sum%mod)+(tmp%mod))%mod;
        }
        sum%=mod;
        ll ans=binpow(n,k-1,mod);
        ans=((ans%mod)*(k%mod))%mod;
        ans=(sum*ans)%mod;
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}