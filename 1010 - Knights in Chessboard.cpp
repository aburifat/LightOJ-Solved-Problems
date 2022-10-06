#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    ll m,n;
    for(ll T=1;T<=t;T++){
        cin>>m>>n;
        if(m>n)swap(m,n);
        ll ans=0;
        if(m==1)ans=n;
        else if(m==2){
            if(n==2)ans=m*n;
            else{
                ll res=n%4;
                n-=res;
                ans=n;
                res=min(res,(ll)2);
                res*=2;
                ans+=res;
            }
        }
        else{
            ans=m*n;
        	ans=(ans/2)+(ans%2);
        }
        cout<<"Case "<<T<<": "<<ans<<"\n";
    }
    return 0;
}