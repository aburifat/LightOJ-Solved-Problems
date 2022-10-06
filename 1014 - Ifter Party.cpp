/*
*   Judge       : LightOJ
*   Problem     : 1014 - Ifter Party
*   Algorithms  : Finding Divisors
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

int main()
{
    ll t;
    scanf("%lld",&t);
    ll L,P;
    for(ll T=1;T<=t;T++){
        scanf("%lld %lld",&L,&P);
        ll res=L-P;
        if(res<=P){
            printf("Case %lld: impossible\n",T);
            continue;
        }
        vector<ll>fst,lst;
        for(ll i=1;(i*i)<=res;i++){
            if(res%i==0){
                fst.push_back(i);
                if(i!=(res/i))lst.push_back(res/i);
            }
        }
        printf("Case %lld: ",T);
        ll ck=0;
        for(auto u:fst){
            if(u<=P)continue;
            if(!ck)ck=1;
            else printf(" ");
            printf("%lld",u);
        }
        ll len=lst.size();
        for(ll i=len-1;i>=0;i--){
            if(lst[i]<=P)continue;
            if(!ck)ck=1;
            else printf(" ");
            printf("%lld",lst[i]);
        }
        printf("\n");
    }
    return 0;
}



