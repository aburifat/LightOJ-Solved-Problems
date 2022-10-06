#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<ll,ll>a, pair<ll,ll>b)
{
    if(a.first<b.first)return true;
    else if((a.first==b.first)&&(a.second>b.second))return true;
    return false;
}

vector<pair<ll,ll> >nod;
void nodAll(ll n) {
    nod.resize(n+1);
    nod[0]={0,0};
    nod[1]={1,1};
    for(ll i=2; i<=n; i++) nod[i]={1,i};
    for(ll i=2; i<=n; i++) {
        if(nod[i].first==1) {
            for(ll j=i; j<=n; j+=i) {
                ll power=0, val=i;
                while(j%val==0) {
                    power++;
                    val*=i;
                }
                ll tmp=nod[j].first;
                tmp*=(power+1);
                nod[j].first=tmp;
            }
        }
    }
    sort(nod.begin(),nod.end(),cmp);
}


int main() {
    nodAll(1000);
    ll t;
    ll n;
    cin>>t;
    for(ll T=1;T<=t;T++){
        cin>>n;
        ll ans=nod[n].second;
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
