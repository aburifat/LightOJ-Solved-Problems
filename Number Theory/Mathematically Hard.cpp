/*
*   Judge       : LightOJ
*   Problem     : Mathematically Hard
*   Algorithms  : Euler Phi
*   Solved By   : Abu Rifat Muhammed Al Hasib
*   Website     : aburifat.com
*   Email       : rifat.cse4.bu@gmail.com
*   GitHub      : github.com/abu-rifat
*   Codeforces  : codeforces.com/profile/AbuRifatMuhammed
*   Education   : University of Barishal
*/

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

constexpr ll MX=5000000;

ll phi[MX+9];

void init()
{
    phi[0]=0;
    phi[1]=1;
    for(ll i=2; i<=MX;i++) phi[i]=i;
    for(ll i=2;i<=MX;i++){
        if(phi[i]==i){
            for(ll j=i;j<=MX;j+=i){
                phi[j]-=(phi[j]/i);
            }
        }
    }
    for(ll i=1;i<=MX;i++){
        phi[i]*=phi[i];
        phi[i]+=phi[i-1];
    }
}

int main()
{
    init();
    ll t;
    scanf("%llu",&t);
    ll a,b;
    for(ll T=1;T<=t;T++){
        scanf("%llu %llu",&a,&b);
        ll ans=phi[b]-phi[a-1];
        printf("Case %llu: %llu\n",T,ans);
    }
    return 0;
}


