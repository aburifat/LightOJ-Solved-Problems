#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll PI=(2.0)*acos(0.0);

int main()
{
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        double a, b;
        string s;
        cin>>a>>s>>b;
        double ang=(2.0)*atan(b/a);
        double val=(b/a);
        val*=val;
        val+=(1.0);
        val=sqrt(val);
        double d=(2.0)+(ang*val);
        double x=(400.0)/d;
        double y=(b/a)*x;
        cout<<"Case "<<T<<": ";
        cout<<fixed<<setprecision(10)<<x<<" "<<y<<"\n";
    }
    return 0;
}