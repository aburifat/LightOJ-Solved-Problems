#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(a) cout<<#a" = "<<a<<"\n"
#define cs(T,val) cout<<"Case "<<T<<": "<<val<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll nCr[35][35]; //initiate with -1
ll nCr_DP(ll n, ll r) {
    if(nCr[n][r]!=-1)return nCr[n][r];
    if(n==0||r==0||n==r)return nCr[n][r]=1;
    return nCr[n][r]=nCr_DP(n-1,r)+nCr_DP(n-1,r-1);
}

ll fct[35];
ll fact(ll n) {
    fct[0]=1;
    for(ll i=1; i<=n; i++) {
        fct[i]=fct[i-1]*i;
    }
}

int main() {
    fast;
    fact(30);
    ll t;
    cin>>t;
    ll n,k;
    for(ll T=1; T<=t; T++) {
        cin>>n>>k;
        if(k>n) {
            cs(T,0);
            continue;
        }
        for(ll i=0; i<=n; i++) {
            for(ll j=0; j<=k; j++) {
                nCr[i][j]=-1;
            }
        }
        ll ans=nCr_DP(n,k);
        ans=ans*ans;
        ans*=fct[k];
        cs(T,ans);

    }
    return 0;
}
