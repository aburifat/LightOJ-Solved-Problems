#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

constexpr ll MX = 1e6;
constexpr ll LIM = 1e7;

ll gcd(ll a, ll b)
{
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    ll t;
    cin>>t;
    ll a, b, L;
    for(ll T=1;T<=t;T++){
        cin>>a>>b>>L;
        cout<<"Case "<<T<<": ";
        ll k=lcm(a,b);
        vector<ll>fct;
        ll sq=sqrt(k);
        for(ll i=1;i<=sq;i++){
                if(k%i==0){
                    fct.push_back(i);
                    if((k/i)!=i)fct.push_back(k/i);
                }
        }
        sort(fct.begin(),fct.end());
        ll len=fct.size();
        ll c,ck=0;
        for(ll i=len-1;i>=0;i--){
            if(L%fct[i]==0){
                c=L/fct[i];
                if(lcm(c,k)==L){
                    ck=1;
                    cout<<c<<"\n";
                    break;
                }
            }
        }
        if(!ck)cout<<"impossible\n";
    }
    return 0;
}
