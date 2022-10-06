#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MOD = 1e9+7;
constexpr ll MX = 1005;


ll exGCD(ll a, ll b, ll &x, ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll d=exGCD(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return d;
}

ll binpow(ll base, ll power, ll mod)
{
    base%=mod;
    // If mod is prime, power=power%(mod-1);
    ll result=1;
    while(power>0)
    {
        if(power&1)result=(result*base)%mod;
        base=(base*base)%mod;
        power>>=1;
    }
    return result;
}

ll modInv(ll a, ll mod)
{
    return binpow(a,mod-2,mod);
}

ll gcd(ll a, ll b)
{
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

int main() {
    ll t;
    cin>>t;
    ll n, k;
    for(ll T=1; T<=t; T++) {
        cin>>n>>k;
        ll inv_n=modInv(n,MOD);
        ll ans=0;
        for(ll d=1; d<=n; d++) {
            ll tmp_ans=binpow(k,gcd(n,d),MOD);
            ans=((ans%MOD)+(tmp_ans%MOD))%MOD;
        }
        ans=((ans%MOD)*(inv_n%MOD))%MOD;
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
