#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double PI=2.0*acos(0.0);

int main()
{
    ll t;
    cin>>t;
    double r1, r2, h, p;
    for(ll T=1;T<=t;T++){
        cin>>r1>>r2>>h>>p;
        double hp=(h*r2)/(r1-r2);
        double rp=(r2*(p+hp))/hp;
        double vol=PI/(3.0);
        vol*=((rp*rp*(p+hp))-(r2*r2*hp));
        cout<<"Case "<<T<<": ";
        cout<<fixed<<setprecision(9)<<vol<<endl;
    }
    return 0;
}