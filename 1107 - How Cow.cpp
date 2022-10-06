#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin>>t;
    ll x1,x2,y1,y2;
    for(ll T=1;T<=t;T++){
        cin>>x1>>y1>>x2>>y2;
        if(x1>x2)swap(x1,x2);
        if(y1>y2)swap(y1,y2);
        ll m;
        cin>>m;
        ll x,y;
        cout<<"Case "<<T<<":\n";
        for(ll i=0;i<m;i++){
            cin>>x>>y;
            if(x>x1&&x<x2&&y>y1&&y<y2)cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
    return 0;
}