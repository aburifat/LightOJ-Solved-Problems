/*
*   Judge       : LightOJ
*   Problem     : 1028 - Trailing Zeroes (I)
*   Algorithms  : NOD(Number of Divisors)
*   Solved By   : Abu Rifat Muhammed Al Hasib
*   Website     : aburifat.com
*   Email       : rifat.cse4.bu@gmail.com
*   GitHub      : github.com/abu-rifat
*   Codeforces  : codeforces.com/profile/AbuRifatMuhammed
*   Education   : University of Barishal
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bitset<1000020>bs;
vector<ll>primes;

void sieve(ll ub)
{
    bs.set();
    bs[0]=bs[1]=0;
     primes.push_back(2);
     for(ll i=4;i<=ub;i+=2)bs[i]=0;
     for(ll i=3;i<=ub;i+=2){
        if(bs[i]){
            for(ll j=i*i;j<=ub;j+=(2*i))bs[j]=0;
            primes.push_back(i);
        }
     }
}

int main()
{
    sieve(1000010);
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        ll n;
        cin>>n;
        ll ans=1;
        for(ll i=0;primes[i]*primes[i]<=n;i++){
            if(n%primes[i]==0){
                ll ct=0;
                while(n%primes[i]==0){
                    n/=primes[i];
                    ct++;
                }
                if(ct)ans*=(ct+1);
            }
        }
        if(n>1)ans*=2;
        cout<<"Case "<<T<<": "<<ans-1<<"\n";
    }
    return 0;
}

