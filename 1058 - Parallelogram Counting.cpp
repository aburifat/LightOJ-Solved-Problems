#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        ll n;
        cin>>n;
        vector<pair<ll,ll> >points;
        for(ll i=0;i<n;i++){
            ll x,y;
            cin>>x>>y;
            points.push_back({x,y});
        }
        vector<pair<double,double> >midles;
        double midx,midy;
        pair<double,double>pr;
        for(ll i=0;i<n-1;i++){
            for(ll j=i+1;j<n;j++){
                ll ck1=0,ck2=0;
                midx=points[i].first+points[j].first;
                midx/=(2.0);
                midy=points[i].second+points[j].second;
                midy/=(2.0);
                pr={midx,midy};
                midles.push_back(pr);
            }
        }
        sort(midles.begin(),midles.end());
        ll len=midles.size(); 
        ll ans=0;
        ll ct=0;
        for(ll i=0;i<len;i++){
            if(i==0){
                pr=midles[i];
                ct=1;
            }
            else if(midles[i]==pr)ct++;
            else{
                if(ct>1){
                    ll val=ct*(ct-1);
                    val/=2;
                    ans+=val;
                }
                ct=1;
                pr=midles[i];
            }
            if(i==(len-1)){
                if(ct>1){
                    ll val=ct*(ct-1);
                    val/=2;
                    ans+=val;
                }
            }
        }
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}