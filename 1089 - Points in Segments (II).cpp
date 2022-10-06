#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX = 1e5;

ll A[MX+10],tree[(4*MX)+10],lazy[(4*MX)+10];
vector<ll>points,p2;
map<ll,ll>mp;

void init(){
    points.clear();
    p2.clear();
    mp.clear();
    memset(A,0,sizeof(A));
    memset(lazy,0,sizeof(lazy));
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
    if(lazy[node]!=0){
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[2*node]+=lazy[node];
            lazy[(2*node)+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if((start>end)||(r<start)||(end<l))return 0;
    if((l<=start)&&(end<=r))return tree[node];
    ll mid=(start+end)/2;
    ll p1=query((2*node),start,mid,l,r);
    ll p2=query(((2*node)+1),(mid+1),end,l,r);
    return p1+p2;
}

void update(ll node, ll start, ll end, ll l, ll r, ll val){
    if(lazy[node]!=0){
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[2*node]+=lazy[node];
            lazy[(2*node)+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if((start>end)||(start>r)||(end<l))return;
    if((start>=l)&&(end<=r)){
        tree[node]+=(end-start+1)*val;
        if(start!=end){
            lazy[2*node]+=val;
            lazy[(2*node)+1]+=val;
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
        ll s, p;
        cin>>s>>p;
        vector<pair<ll,ll> >q;
        ll a, b;
        for(ll i=0;i<s;i++){
            cin>>a>>b;
            q.push_back({a,b});
        }
        ll val;
        points.push_back(-1);
        for(ll i=0;i<p;i++){
            cin>>val;
            if(mp[val]==0)points.push_back(val);
            mp[val]++;
        }
        p2=points;
        sort(points.begin(),points.end());
        ll n=points.size();
        ll st=points[1];
        ll ed=points[n-1];
         mp.clear();
        for(ll i=1;i<n;i++){
            mp[points[i]]=i;
        }
        for(ll i=0;i<s;i++){
            ll l=q[i].first;
            ll r=q[i].second;
            l=lower_bound(points.begin(),points.end(),l)-points.begin();
            r=upper_bound(points.begin(),points.end(),r)-points.begin();
            r--;
            //cout<<l<<" "<<r<<"\n";
            if((l>=n)||(r<=0)||(l>r))continue;
            update(1,1,n-1,l,r,1);
        }
        cout<<"Case "<<T<<":\n";
        for(ll i=1; i<n; i++){
            ll idx=mp[p2[i]];
            ll ans=query(1,1,n-1,idx,idx);
            cout<<ans<<"\n";
        }
    }
    return 0;
}