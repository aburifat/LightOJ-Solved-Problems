#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>num;
ll dp[30][30][2][2];

ll dgtDP(ll pos, ll cnt, ll topDgt, ll notLead)
{
    if(pos==num.size()){
        return cnt;
    }
    if(dp[pos][cnt][topDgt][notLead]!=-1)return dp[pos][cnt][topDgt][notLead];
    ll ans=0;
    ll lmt=(topDgt)?num[pos]:9;
    for(ll dgt=0;dgt<=lmt;dgt++){
        ll ncnt=(notLead)?(cnt+(dgt==0)) : 0;
        ll ntopDgt=(topDgt&&(dgt == num[pos]));
        ll nnotLead=((dgt!=0)||notLead);
        ans+=dgtDP(pos+1,ncnt,ntopDgt,nnotLead);
    }
    return dp[pos][cnt][topDgt][notLead]=ans;
}

ll solve(ll n)
{
    num.clear();
    if(n==-1)return -1;
    while(n>0){
        num.push_back(n%10);
        n/=10;
    }
    reverse(num.begin(),num.end());
    memset(dp,-1,sizeof(dp));
    ll ans=dgtDP(0,0,1,0);
    return ans;
}

int main()
{
    ll t;
    cin>>t;
    ll a, b;
    for(ll T=1;T<=t;T++){
        cin>>a>>b;
        ll ans;
        ans=solve(b)-solve(a-1);
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
