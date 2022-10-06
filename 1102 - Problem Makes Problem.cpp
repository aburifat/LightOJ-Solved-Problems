#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll mod = 1000000007;
constexpr ll mx = 2000050;

vector<ll>fact;
void fact_mod(ll n, ll mod) {
    fact.resize(n+5);
    fact[0]=1;
    fact[1]=1;
    for(ll i=2; i<=n; i++) {
        fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
    }
}

ll exGCD(ll a, ll b, ll &x, ll &y) {
    if(b==0) {
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

ll modInv(ll a, ll mod) {
    ll x, y;
    ll g=exGCD(a,mod,x,y);
    if(g!=1) {
        cout<<"Not Good\n";
        return -1;
    }
    x=(x%mod+mod)%mod;
    return x;
}

ll bigMul(ll a, ll b, ll mod) {
    if(a==0)return 0;
    ll ans=(2*bigMul(a/2,b,mod))%mod;
    if(a&1)ans=(ans+(b%mod))%mod;
    return ans;
}

ll nCr(ll n, ll r, ll mod) {
    ll res=fact[n];
    ll res_down=((fact[n-r]%mod)*(fact[r]%mod))%mod;
    res_down=modInv(res_down,mod);
    res=((res%mod)*(res_down%mod))%mod;
    return res;
}

int main() {
    fact_mod(mx,mod);
    ll t;
    cin>>t;
    ll n, k;
    for(ll T=1; T<=t; T++) {
        cin>>n>>k;
        ll ans=nCr(n+k-1,k-1,mod);
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
