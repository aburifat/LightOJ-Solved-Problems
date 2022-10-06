#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX = 1000000;

ll spFacts[1000006][2];
void ctSpFact()
{
    for(ll i=0;i<=MX;i++){
        spFacts[i][0]=spFacts[i][1]=0;
    }
    for(ll i=2;i<=MX;i++){
        ll num=i;
        while(num%2==0){
            spFacts[i][0]++;
            num/=2;
        }
        num=i;
        while(num%5==0){
            spFacts[i][1]++;
            num/=5;
        }
    }
    for(ll i=1;i<=MX;i++){
        spFacts[i][0]+=spFacts[i-1][0];
        spFacts[i][1]+=spFacts[i-1][1];
    }
}

int main()
{
    ctSpFact();
    ll t;
    cin>>t;
    ll n,r,p,q;
    for(ll T=1;T<=t;T++){
        cin>>n>>r>>p>>q;
        ll twos=spFacts[n][0]-spFacts[n-r][0]-spFacts[r][0]+((spFacts[p][0]-spFacts[p-1][0])*q);
        ll fives=spFacts[n][1]-spFacts[n-r][1]-spFacts[r][1]+((spFacts[p][1]-spFacts[p-1][1])*q);
        ll ans=min(twos,fives);
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
