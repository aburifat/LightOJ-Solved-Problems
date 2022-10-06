#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin>>t;
    ll s;
    for(ll T=1;T<=t;T++){
        cin>>s;
        ll sq=sqrt(s);
        ll rem=s-(sq*sq);
        if(!rem){
            sq--;
            rem=s-(sq*sq);
        }
        ll x,y;
        if(sq%2==0){
            x=sq+1;
            y=0;
            y+=min(sq+1,rem);
            rem=max((ll)0,(rem-sq-1));
            x-=rem;
        }else{
            y=sq+1;
            x=0;
            x+=min(sq+1,rem);
            rem=max((ll)0,(rem-sq-1));
            y-=rem;
        }
        cout<<"Case "<<T<<": "<<x<<" "<<y<<"\n";
    }
}