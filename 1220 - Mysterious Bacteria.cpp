#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX = 1e6;

bitset<1000010>bs;
vector<ll>primes;
void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;
    primes.push_back(2);
    for(ll i=4;i<=MX;i+=2)bs[i]=0;
    for(ll i=3;i<=MX;i+=2){
        if(bs[i]){
            primes.push_back(i);
            for(ll j=i*i;j<=MX;j+=i)bs[j]=0;
        }
    }
}

int main()
{
    sieve();
    ll t;
    cin>>t;
    ll x;
    for(ll T=1;T<=t;T++){
        cin>>x;
        bool pos=true;
        if(x<0)pos=false;
        x=abs(x);
        cout<<"Case "<<T<<": ";
        vector<ll>pf;
        ll num=x;
        for(ll i=0;primes[i]*primes[i]<=num;i++){
            if(num%primes[i]==0){
                pf.push_back(primes[i]);
                while(num%primes[i]==0){
                    num/=primes[i];
                }
            }
        }
        if(num>1)pf.push_back(num);
        ll ct=0;
        ll len=pf.size();
        ll arr[len+5];
        for(ll i=0;i<len;i++){
            arr[i]=0;
            while(x%pf[i]==0){
                x/=pf[i];
                arr[i]++;
            }
        }
        ll g=arr[0];
        for(ll i=1;i<len;i++){
            g=__gcd(g,arr[i]);
        }
        if(!pos){
            while(g%2==0)g/=2;
        }
        cout<<g<<"\n";
    }
    return 0;
}