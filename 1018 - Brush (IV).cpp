#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll,ll> points[17];
ll dp[(1<<16)+3][17];
ll preVal[17][17];
ll n;

ll call(ll i, ll mask){
    if(i>=n)return 0;
    if(mask==((1<<n)-1))return 0;
    if(dp[mask][i]!=-1)return dp[mask][i];
    ll mn=(1<<20);
    if((mask&(1<<i))==0){
        mn=min(mn,1+call(i+1,mask|(1<<i)));
        for(ll j=i+1;j<n;j++){
            if((mask&(1<<j))==0){
                mn=min(mn,1+call(i,mask|preVal[i][j]));
            }
        }
    }else{
        mn=min(mn,call(i+1,mask));
    }
    return dp[mask][i]=mn;
}

void pre(){
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll xi=points[i].first;
            ll yi=points[i].second;
            ll xj=points[j].first;
            ll yj=points[j].second;
            ll tgty=(yi-yj);
            ll tgtx=(xi-xj);
            ll g=__gcd(tgtx,tgty);
            if(g!=0){
                tgty/=g;
                tgtx/=g;
            }
            ll mask=0;
            mask|=(1<<i);
            mask|=(1<<j);
            for(ll k=j+1;k<n;k++){
                ll xk=points[k].first;
                ll yk=points[k].second;
                ll ty=(yi-yk);
                ll tx=(xi-xk);
                ll gk=__gcd(tx,ty);
                if(g!=0){
                    ty/=gk;
                    tx/=gk;
                }
                if((tgty==ty)&&(tgtx==tx))mask|=(1<<k);
            }
            preVal[i][j]=mask;
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    scanf("%lld",&t);
    for(ll T=1;T<=t;T++){
        memset(dp,-1,sizeof(dp));
        //memset(preVal,-1,sizeof(preVal));
        scanf("%lld",&n);
        ll x,y;
        for(ll i=0;i<n;i++){
            scanf("%lld %lld",&x,&y);
            points[i].first=x;
            points[i].second=y;
        }
        pre();
        ll ans=(1<<20);
        ll mask=0;
        for(ll i=0;i<n;i++){
            ans=min(ans,i+call(i,mask));
            mask|=(1<<i);
        }
        printf("Case %lld: %lld\n",T,ans);
    }
    return 0;
}