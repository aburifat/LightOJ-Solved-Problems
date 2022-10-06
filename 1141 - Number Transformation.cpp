#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>facts[1010];
ll alen,blen;
ll cnt[1010];

void findPF(){
    for(ll i=2;i<1010;i++){
        ll n=i;
        for(ll j=2;j<=sqrt(i);j++){
            if(n%j==0){
                facts[i].push_back(j);
                while(n%j==0)n/=j;
            }
        }
        if((n!=1)&&(n!=i))facts[i].push_back(n);
    }
}

ll dfs(ll s,ll des)
{
    if(s==des)return 0;
    if(s>des)return INT_MAX;
    if(cnt[s]!=-1)return cnt[s];
    ll val=INT_MAX;
    for(ll i=0;i<(ll)facts[s].size();i++){
        val=min(val,1+dfs(s+facts[s][i],des));
    }
    return cnt[s]=val;
}

int main()
{
    findPF();
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        memset(cnt,-1,sizeof(cnt));
        ll a, b;
        cin>>a>>b;
        ll ans;
        if(b<a)ans=-1;
        else if(b==a)ans=0;
        else if((ll)facts[a].size()==0)ans=-1;
        else{
            ans=dfs(a,b);
            if(ans==INT_MAX)ans=-1;
        }
res:
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}