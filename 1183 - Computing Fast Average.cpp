#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX = 1e5;

ll A[MX+10],tree[(4*MX)+10],lazy[(4*MX)+10];

void init(){
    memset(A,0,sizeof(A));
    memset(lazy,-1,sizeof(lazy));
    memset(tree,0,sizeof(tree));
}

/*
void build(ll node, ll start, ll end){
    if(start==end)tree[node]=A[start];
    else{
        ll mid=(start+end)/2;
        build((2*node), start, mid);
        build(((2*node)+1),(mid+1),end);
        tree[node]=tree[(2*node)]+tree[(2*node)+1];
    }
}
*/

ll query(ll node,ll start, ll end, ll l, ll r){
    if(lazy[node]!=-1){
        tree[node]=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[2*node]=lazy[node];
            lazy[(2*node)+1]=lazy[node];
        }
        lazy[node]=-1;
    }
    if((start>end)||(r<start)||(end<l))return 0;
    if((l<=start)&&(end<=r))return tree[node];
    ll mid=(start+end)/2;
    ll p1=query((2*node),start,mid,l,r);
    ll p2=query(((2*node)+1),(mid+1),end,l,r);
    return p1+p2;
}

void update(ll node, ll start, ll end, ll l, ll r, ll val){
    if(lazy[node]!=-1){
        tree[node]=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[2*node]=lazy[node];
            lazy[(2*node)+1]=lazy[node];
        }
        lazy[node]=-1;
    }
    if((start>end)||(start>r)||(end<l))return;
    if((start>=l)&&(end<=r)){
        tree[node]=(end-start+1)*val;
        if(start!=end){
            lazy[2*node]=val;
            lazy[(2*node)+1]=val;
        }
        return;
    }
    int mid=(start+end)/2;
    update((2*node),start,mid,l,r,val);
    update(((2*node)+1),(mid+1),end,l,r,val);
    tree[node]=tree[2*node]+tree[(2*node)+1];
    //cout<<node<<" "<<tree[node]<<"\n";
}

int main(){
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        init();
        ll n, q;
        cin>>n>>q;
        ll ck,l,r,v;
        cout<<"Case "<<T<<":\n";
        for(ll i=0;i<q;i++){
            cin>>ck;
            if(ck==1){
                cin>>l>>r>>v;
                update(1,1,n,l+1,r+1,v);
            }else{
                cin>>l>>r;
                ll ans=query(1,1,n,l+1,r+1);
                ll dis=(r-l+1);
                ll g=__gcd(dis,ans);
                ans/=g;
                dis/=g;
                cout<<ans;
                if(dis!=1)cout<<"/"<<dis;
                cout<<"\n";
            }
        }
    }
    return 0;
}