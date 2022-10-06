#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX = 400000015;
constexpr ll LIM = 5000000000;

ll ct(ll n)
{
    ll ans=0;
    for(ll i=1;;i++){
        ll val=pow(5,i);
        if(val>n)break;
        ans+=(n/val);
    }
    return ans;
}

ll bs(ll L, ll R, ll q)
{
    ll mid=L+(R-L)/2;
    ll tmp=ct(mid);
    if(L>R)return LIM;
    if((L==R)&&(tmp!=q))return LIM;
    if(tmp==q){
        if(L==R)return L;
        else return bs(L,mid,q);
    }else if(tmp<q){
        return bs(mid+1,R,q);
    }else{
        return bs(L,mid-1,q);
    }
}

int main()
{
    ll t;
    cin>>t;
    ll q;
    for(ll T=1;T<=t;T++){
        cin>>q;
        ll ans=bs((ll)1,MX,q);
        cout<<"Case "<<T<<": ";
        if(ans==LIM)cout<<"impossible\n";
        else cout<<ans<<"\n";
    }
    return 0;
}
