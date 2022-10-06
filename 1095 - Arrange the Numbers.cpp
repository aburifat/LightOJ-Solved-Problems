#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll mod = 1e9+7;
constexpr ll MX = 1e3+5;

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
    if(g!=1)
        return -1; //No Solution
    x=(x%mod+mod)%mod;
    return x;
}



ll nCr(ll n, ll r, ll mod) {
    ll res=fact[n];
    ll res_down=((fact[n-r]%mod)*(fact[r]%mod))%mod;
    res_down=modInv(res_down,mod);
    res=((res%mod)*(res_down%mod))%mod;
    return res;
}

ll darg(ll a, ll b){
    ll ans=0;
    bool tog=true;
    for(ll i=0;i<=b;i++){
        ll tmp_ans=(fact[a-i]*nCr(b,i,mod))%mod;
        if(tog==true){
            ans=(ans+tmp_ans)%mod;
            tog=false;
        }else{
            ans=(ans-tmp_ans+mod)%mod;
            tog=true;
        }

    }
    return ans;
}


int main() {
    fact_mod(MX,mod);
    ll t;
    cin>>t;
    ll n, m, k;
    for(ll T=1; T<=t; T++) {
        cin>>n>>m>>k;
        ll ans=darg(n-k,m-k);
        ans=(nCr(m,k,mod)*ans)%mod;
        cout<<"Case "<<T<<": ";
        cout<<ans<<endl;
    }
    return 0;
}
