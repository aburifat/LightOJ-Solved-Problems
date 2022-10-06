#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX = 100000;

bitset<100010>bs;
vector<ll>primes;
void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;
    primes.push_back(2);
    for(ll i=4;i<=MX;i+=2)bs[i]=0;
    for(ll i=3;i<=MX;i+=2){
        if(bs[i]==1){
            primes.push_back(i);
            for(ll j=i*i;j<=MX;j+=i)bs[j]=0;
        }
    }
}

int main()
{
    sieve();
    ll len=primes.size();
    ll t;
    ll l, r;
    cin>>t;
    for(ll T=1; T<=t;T++){
        cin>>l>>r;
        bitset<100005>newbs;
        newbs.set();
        for(ll i=0;i<len;i++){
            //if(primes[i]*primes[i]>r)break;
            ll val=l/primes[i];
            if(l%primes[i]!=0)val++;
            val*=primes[i];
            if(l==0){
                newbs[0]=newbs[1]=0;
            }else if(l==1){
                newbs[0]=0;
            }
            if(val==primes[i])val+=primes[i];
            for(ll j=val;j<=r;j+=primes[i]){
                newbs[j-l]=0;
            }
        }
        ll ans=0;
        for(ll i=0;i<=(r-l);i++)if(newbs[i])ans++;
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
