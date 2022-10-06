#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin>>t;
    ll n;
    for(ll T=1;T<=t;T++){
        cin>>n;
        ll ans=0;
        for(ll i=2;i*i<=n;i++){
            ll j=n/i;
            ans+=(j+i)*(j-i+1)/2;
            ans+=(j-i)*i;
        }
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
