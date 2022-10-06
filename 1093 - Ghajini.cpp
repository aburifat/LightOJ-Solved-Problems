#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX = 1e5;

ll A[MX+10],tree[(4*MX)+10][2];

void init(){
    memset(tree,0,sizeof(tree));
}

void build(ll node, ll start, ll end){
    if(start==end)tree[node][0]=tree[node][1]=A[start];
    else{
        ll mid=(start+end)/2;
        build((2*node), start, mid);
        build(((2*node)+1),(mid+1),end);
        tree[node][0]=min(tree[(2*node)][0],tree[(2*node)+1][0]);
        tree[node][1]=max(tree[(2*node)][1],tree[(2*node)+1][1]);
    }
}

pair<ll,ll> query(ll node,ll start, ll end, ll l, ll r){
    if((start>end)||(r<start)||(end<l))return {LONG_MAX,LONG_MIN};
    if((l<=start)&&(end<=r))return {tree[node][0],tree[node][1]};
    ll mid=(start+end)/2;
    pair<ll,ll> p1=query((2*node),start,mid,l,r);
    pair<ll,ll> p2=query(((2*node)+1),(mid+1),end,l,r);
    return {min(p1.first,p2.first),max(p1.second,p2.second)};
}

int main(){
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        init();
        ll n, d;
        cin>>n>>d;
        for(ll i=1;i<=n;i++)cin>>A[i];
        build(1,1,n);
        ll ans=0;
        for(ll i=1;i<=d;i++){
            pair<ll,ll>val=query(1,1,n,1,i);
            ans=max(ans,abs(val.second-val.first));
        }
        for(ll i=d+1;i<=n;i++){
            pair<ll,ll>val=query(1,1,n,i-d+1,i);
            ans=max(ans,abs(val.second-val.first));
        }
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}