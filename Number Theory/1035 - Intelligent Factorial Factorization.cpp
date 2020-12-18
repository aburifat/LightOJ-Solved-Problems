/*
*   Judge       : LightOJ
*   Problem     : 1035 - Intelligent Factorial Factorization
*   Algorithms  : Prime Factorization
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

bitset<110>bs;
vector<ll>primes;
ll facts[110][50];

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

void inis()
{
    for(ll i=0;i<=100;i++){
        for(ll j=0;j<50;j++){
            facts[i][j]=0;
        }
    }
}

int main()
{
    sieve(110);
    inis();
    ll pLen=primes.size();
    for(ll i=2;i<=100;i++){
        ll num=i;
        for(ll j=0;j<pLen;j++)facts[i][j]=facts[i-1][j];
        for(ll j=0;primes[j]*primes[j]<=num;j++){
            ll ct=0;
            while(num%primes[j]==0){
                ct++;
                num/=primes[j];
            }
            facts[i][j]+=ct;
        }
        if(num>1){
            ll idx=upper_bound(primes.begin(),primes.end(),num)-primes.begin();
            idx--;
            facts[i][idx]+=1;
        }
    }
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        ll n;
        cin>>n;
        cout<<"Case "<<T<<": "<<n<<" =";
        ll ck=0;
        for(ll i=0;i<pLen;i++){
            if(facts[n][i]){
                if(!ck)ck++;
                else cout<<" *";
                cout<<" "<<primes[i]<<" ("<<facts[n][i]<<")";
            }
        }
        cout<<"\n";
    }
    return 0;
}

