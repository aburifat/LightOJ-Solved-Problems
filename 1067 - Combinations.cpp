#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll mod = 1000003;
constexpr ll mx = 1000050;


ll bigMul(ll a, ll b, ll mod)
{
    if(a==0)return 0;
    ll ans=(2*bigMul(a/2,b,mod))%mod;
    if(a&1)ans=(ans+(b%mod))%mod;
    return ans;
}

vector<ll>fact;
void calFact(ll n, ll mod)
{
    fact.resize(n+1);
    fact[0]=1;
    for(ll i=1; i<=n; i++)
    {
        fact[i]=bigMul(fact[i-1],i,mod);
    }
}

ll binpow(ll base, ll power, ll mod)
{
    base%=mod;
    // If mod is prime, 
    power=power%(mod-1);
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


ll nCr(ll n, ll k, ll mod)
{
    if(n<k)return 0;
    ll p_a=fact[n];
    ll p_b=modInv(fact[k],mod);
    ll p_c=modInv(fact[n-k],mod);
    ll ans=bigMul(p_a,p_b,mod);
    ans=bigMul(ans,p_c,mod);
    return ans;
}

int main() {
    calFact(mx,mod);
    ll t;
    cin>>t;
    ll n, k;
    for(ll T=1; T<=t; T++) {
        cin>>n>>k;
        ll ans=nCr(n,k,mod);
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
