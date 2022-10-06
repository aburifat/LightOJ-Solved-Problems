#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(a) cout<<#a" = "<<a<<"\n"
#define cs(T,val) cout<<"Case "<<T<<": "<<val<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll mem[110][110][2];
ll arr[110][110];
ll n;

ll dp(ll i, ll j, ll k=0){
    if(i>=n||j>=n)return 0;
    if(mem[i][j][k]!=-1)return mem[i][j][k];
    ll ans=arr[i][j];
    ans=ans+max(dp(i,j+1,0),dp(i+1,j,1));
    return mem[i][j][k]=ans;
}


int main()
{
    fast;
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        cin>>n;
        for(ll i=0;i<(2*n-1);i++){
            for(ll j=min(i,n-1),k=max(0ll,i-n+1);k<n&&j>=0;j--,k++){
                cin>>arr[j][k];
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                    for(ll k=0;k<2;k++){
                        mem[i][j][k]=-1;
                    }

            }
        }
        ll ans=dp(0,0);
        cs(T,ans);
    }
    return 0;
}
