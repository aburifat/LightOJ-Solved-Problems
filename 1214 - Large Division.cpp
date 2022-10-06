#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool bigDiv(string s, ll n)
{
    if(n<0)n=(-n);
    ll idx=0;
    if(s[0]=='-')idx++;
    ll len=s.size();
    ll num=0;
    for(ll i=idx;i<len;i++){
        num*=10;
        num+=(s[i]-'0');
        if(num>=n){
            num%=n;
        }
    }
    if(num==0)return true;
    else return false;
}

int main()
{
    ll t;
    cin>>t;
    string s;
    ll n;
    for(ll T=1;T<=t;T++){
        cin>>s>>n;
        cout<<"Case "<<T<<": ";
        if(bigDiv(s,n))cout<<"divisible\n";
        else cout<<"not divisible\n";
    }
    return 0;
}
