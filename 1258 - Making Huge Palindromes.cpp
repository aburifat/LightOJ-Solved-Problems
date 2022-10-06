#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>rHash[4],rHashR[4];
ll base[]= {29,31,37,41};
ll mod[]= {1000000007,1000000009,1000000021,1000000033};
ll basePow[4][1000006];
ll hashct=1;

void ctBasePow()
{
    for(ll i=0; i<hashct; i++)basePow[i][0]=1;
    for(ll i=1; i<=1000000; i++)
    {
        for(ll j=0; j<hashct; j++)
        {
            basePow[j][i]=(basePow[j][i-1]*base[j])%mod[j];
        }
    }
}

void ctRollHash(string s)
{
    ll len=s.size();
    ll ch=s[0]-'a'+1;
    for(ll i=0; i<hashct; i++)
    {
        rHash[i].resize(len+5);
        rHash[i][0]=ch;
    }
    for(ll i=1; i<len; i++)
    {
        for(ll j=0; j<hashct; j++)
        {
            rHash[j][i]=(((rHash[j][i-1]*base[j])%mod[j])+(s[i]-'a'+1))%mod[j];
        }
    }
    reverse(s.begin(),s.end());
    ch=s[0]-'a'+1;
    for(ll i=0; i<hashct; i++)
    {
        rHashR[i].resize(len+5);
        rHashR[i][0]=ch;
    }
    for(ll i=1; i<len; i++)
    {
        for(ll j=0; j<hashct; j++)
        {
            rHashR[j][i]=(((rHashR[j][i-1]*base[j])%mod[j])+(s[i]-'a'+1))%mod[j];
        }
    }
}

void solve(string s)
{
    ctRollHash(s);
    ll len=s.size();
    ll ct=0;
    ll ans=len;
    for(ll j=0; j<hashct; j++)
    {
        if(rHash[j][len-1]==rHashR[j][len-1])ct++;
    }
    ll ck=0;
    if(ct!=hashct)
    {
        ck=1;
        for(ll i=0;i<len-1;i++){
            ct=0;
            for(ll j=0;j<hashct;j++){
                ll val=rHash[j][len-1];
                val=(val-(rHash[j][i]*basePow[j][len-i-1])%mod[j])%mod[j];
                if(val<0)val+=mod[j];
                ll valr=rHashR[j][len-2-i];
                if(val==valr)ct++;
            }
            if(ct==hashct){
                ans+=(i+1);
                ck=0;
                break;
            }
        }
    }
    if(ck)ans+=len;
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ctBasePow();
    ll t;
    cin>>t;
    string s;
    for(ll T=1; T<=t; T++)
    {
        cin>>s;
        cout<<"Case "<<T<<": ";
        solve(s);
    }
    return 0;
}

