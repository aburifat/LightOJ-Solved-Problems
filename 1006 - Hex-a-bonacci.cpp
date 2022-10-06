#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 10000007;

ll rolling_arr[8][10010];

void init(){
    for(ll i=0;i<6;i++){
        for(ll j=0;j<6;j++){
            if(i==j)rolling_arr[j][i]=1;
            else rolling_arr[j][i]=0;
        }
    }
    for(ll i=0;i<6;i++)rolling_arr[i][6]=1;
    for(ll i=7;i<=10002;i++){
        for(ll j=0;j<6;j++){
            rolling_arr[j][i]=((2*rolling_arr[j][i-1])%mod-(rolling_arr[j][i-7])+mod)%mod;
        }
    }
}

int main(){
    init();
    ll t;
    cin>>t;
    ll a,b,c,d,e,f,n;
    for(ll T=1;T<=t;T++){
        cin>>a>>b>>c>>d>>e>>f>>n;
        ll ans=(((a*rolling_arr[0][n])%mod)+((b*rolling_arr[1][n])%mod)+((c*rolling_arr[2][n])%mod)+((d*rolling_arr[3][n])%mod)+((e*rolling_arr[4][n])%mod)+((f*rolling_arr[5][n])%mod))%mod;
        cout<<"Case "<<T<<": "<<ans<<"\n";
    }
    return 0;
}