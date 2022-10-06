#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX = 1000000;

double LG[1000006];
void ctLog()
{
    LG[0]=0;
    LG[1]=0;
    for(ll i=2;i<=MX;i++){
        LG[i]=log10((double)i);
    }
    for(ll i=1;i<=MX;i++){
        LG[i]+=LG[i-1];
    }
}

int main()
{
    ctLog();
    ll t;
    cin>>t;
    ll n, b;
    for(ll T=1;T<=t;T++){
        cin>>n>>b;
        double newDgt=LG[n];
        newDgt=newDgt/(double)log10((double)b);
        ll ans=floor(newDgt);
        ans++;
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
