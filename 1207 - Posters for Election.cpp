#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX = (2*1e5);

ll A[MX+10],tree[(4*MX)+10],lazy[(4*MX)+10];

void init(){
    memset(A,0,sizeof(A));
    memset(lazy,-1,sizeof(lazy));
    memset(tree,0,sizeof(tree));
}

void build(ll node, ll start, ll end){
    if(start==end)tree[node]=A[start];
    else{
        ll mid=(start+end)/2;
        build((2*node), start, mid);
        build(((2*node)+1),(mid+1),end);
        tree[node]=tree[(2*node)]+tree[(2*node)+1];
    }
}

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
}

int main(){
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        init();
        ll n;
        cin>>n;
        ll l,r;
        ll idx_min=LONG_MAX;
        ll idx_max=LONG_MIN;
        for(ll i=1;i<=n;i++){
            cin>>l>>r;
            idx_min=min(idx_min,min(l,r));
            idx_max=max(idx_max,max(l,r));
            update(1,1,(2*n),l,r,i);
        }
        set<ll>ss;
        for(ll i=idx_min;i<=idx_max;i++){
            ll val=query(1,1,(2*n),i,i);
            if(val!=0)ss.insert(val);
        }
        cout<<"Case "<<T<<": ";
        cout<<(ll)ss.size()<<"\n";
    }
    return 0;
}












