#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void cmp(ll & ad, ll & au, ll bd, ll bu){
    if(bd>bu)swap(bu,bd);
    if((bu<ad&&bd<ad&&bu<au&&bd<au)||(bu>au&&bd>au&&bu>ad&&bd>ad)){
        ad=0;au=0;
    }else{
        ad=max(ad,bd);
        au=min(au,bu);
    }
}

int main()
{
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        ll n;
        cin>>n;
        ll xd,yd,zd,xu,yu,zu;
        ll ck=0;
        for(ll i=0;i<n;i++){
            ll x1,y1,z1,x2,y2,z2;
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            if(ck==0){
                xd=min(x1,x2);
                yd=min(y1,y2);
                zd=min(z1,z2);
                xu=max(x1,x2);
                yu=max(y1,y2);
                zu=max(z1,z2);
                ck=1;
            }else{
                cmp(xd,xu,x1,x2);
                cmp(yd,yu,y1,y2);
                cmp(zd,zu,z1,z2);
            }
        }
        ll ans=abs(xd-xu)*abs(yd-yu)*abs(zd-zu);
        cout<<"Case "<<T<<": ";
        cout<<ans<<endl;
    }
    return 0;
}












