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
        ll x;
        for(ll i=1; i<=9; i++){
            if((n-i)%9==0){
                x=i;
                break;
            }
        }
        ll ans=n-x;
        ans/=9;
        ans*=10;
        cout<<"Case "<<T<<": ";
        ans+=x;
        if(x==9){
            cout<<ans<<" ";
            ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

