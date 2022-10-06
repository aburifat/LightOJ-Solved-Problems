#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double PI=(2.0)*acos(0.0);
double frc=0.000000001;

#define fxd(a) std::cout<<std::fixed<<std::setprecision(a)

int main()
{
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        double r;
        cin>>r;
        double sq=r*r;
        double cir=sq*PI;
        sq*=(4.0);
        double ans=sq-cir;
        ans+=frc;
        cout<<"Case "<<T<<": ";
        fxd(2);
        cout<<ans<<"\n";
    }
    return 0;
}