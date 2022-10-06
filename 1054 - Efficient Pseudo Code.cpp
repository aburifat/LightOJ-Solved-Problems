#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll mod = 1000000007;

bitset<100000009>bs;
vector<ll>primes;
void sieve(ll ub)
{
    bs.set();
    ub++;
    bs[0]=bs[1]=0;
    primes.push_back(2);
    for(ll i=4; i<=ub; i+=2)bs[i]=0;
    for(ll i=3; i<=ub; i+=2)
    {
        if(bs[i])
        {
            for(ll j=i*i; j<=ub; j+=i)bs[j]=0;
            primes.push_back(i);
        }
    }
}

pair<vector<ll>,map<ll,ll> >DPF(ll n) {
    vector<ll>disFact;
    map<ll,ll>factCt;
    for (auto d:primes)
    {
        if(d*d>n)break;
        if(n%d==0)disFact.push_back(d);
        while(n%d==0)
        {
            factCt[d]++;
            n/=d;
        }
    }
    if(n>1){
        if(!factCt[n])disFact.push_back(n);
        factCt[n]++;
    }
    return {disFact,factCt};
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

int main()
{
    sieve(1000000);
    ll t;
    cin>>t;
    ll n, m;
    for(ll T=1;T<=t;T++){
        cin>>n>>m;
        pair<vector<ll>,map<ll,ll> >pr;
        pr=DPF(n);
        vector<ll>PF=pr.first;
        map<ll,ll>factCt=pr.second;
        ll ans=1;
        for(ll i=0;i<(ll)PF.size();i++){
            ll pow=(factCt[PF[i]]*m)+1;
            ll down=modInv(PF[i]-1,mod);
            if(down<0){
                down+=mod;
                down%=mod;
            }
            ll up=binpow(PF[i],pow,mod);
            up=(up-1+mod)%mod;
            ll tmp_ans=(up*down)%mod;
            ans=((ans%mod)*tmp_ans)%mod;
        }
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
