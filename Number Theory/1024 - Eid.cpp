/*
*   Judge       : LightOJ
*   Problem     : 1024 - Eid
*   Algorithms  : Prime Factorization and Big-Number
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

bitset<10509>bs;
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

string strNumMul(string str, ll num)
{
    ll strLen=str.size();
    string tmpStr[strLen];
    ll carry=0;
    ll val=0;
    for(ll i=strLen-1;i>=0;i--){
        val=num*(str[i]-'0');
        val+=carry;
        carry=val/10;
        val%=10;
        str[i]=(val+'0');
    }
    if(carry){
        while(carry){
            char ch=(carry%10)+'0';
            str=ch+str;
            carry/=10;
        }
    }
    return str;
}

int main()
{
    sieve(10500);
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        ll n;
        cin>>n;
        map<ll,ll>pDiv;
        string ans="1";
        for(ll i=0;i<n;i++){
            ll tmp;
            cin>>tmp;
            for(ll j=0;primes[j]<=tmp;j++){
                ll ct=0;
                while(tmp%primes[j]==0){
                    ct++;
                    tmp/=primes[j];
                }
                if(ct>pDiv[primes[j]]){
                    pDiv[primes[j]]=ct;
                }
            }
        }
        ll len=primes.size();
        for(ll i=0;i<len;i++){
            if(pDiv[primes[i]]){
                ll val=powl(primes[i],pDiv[primes[i]]);
                ans=strNumMul(ans,val);
            }
        }
        cout<<"Case "<<T<<": "<<ans<<"\n";
    }
    return 0;
}
