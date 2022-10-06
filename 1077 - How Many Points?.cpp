#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t;
    ll x1, x2, y1, y2;
    cin>>t;
    for( ll T=1; T<=t; T++) {
        cin>>x1>>y1>>x2>>y2;
        ll dx=abs(x1-x2);
        ll dy=abs(y1-y2);
        ll ans=0;
        if(!dx&&!dy)ans=0;
        else if(!dx)ans=dy;
        else if(!dy)ans=dx;
        else{
            ll g=__gcd(dx,dy);
            ll dx0=dx/g;
            ans=dx/dx0;
        }
        ans++;
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
