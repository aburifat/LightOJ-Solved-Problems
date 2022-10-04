#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binpow(ll base, ll power, ll mod)
{
    base%=mod;
    power%=(mod-1);
    ll result=1;
    while(power>0){
        if(power&1)result=(result*base)%mod;
        base=(base*base)%mod;
        power>>=1;
    }
    return result;
}

ll modinv(ll a, ll mod){
    return binpow(a,mod-2,mod);
}

int main(){
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        ll n;
        cin>>n;
        ll p[n+5],r[n+5],y[n+5],z[n+5];//mods,reminders,yi,yi^-1
        for(ll i=0;i<n;i++)cin>>p[i]>>r[i];
        ll MUL=1;
        for(ll i=0;i<n;i++)MUL*=p[i];
        for(ll i=0;i<n;i++)y[i]=MUL/p[i];
        for(ll i=0;i<n;i++)z[i]=modinv(y[i],p[i]);
        ll X=0;
        for(ll i=0;i<n;i++){
            X=(X+(r[i]*y[i]*z[i]))%MUL;
        }
        cout<<"Case "<<T<<": ";
        if(X<0)cout<<"Impossible\n";
        else cout<<X<<endl;
    }
    return 0;
}
