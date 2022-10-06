#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double PI=(2.0)*acos(0.0);
constexpr double frc=0.000000001;

#define fxd(a) cout<<fixed<<setprecision(a)

int main()
{
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        double R, n;
        cin>>R>>n;
        double sigma=PI/n;
        double a=R/cos(sigma);
        double b=a;
        double c=(a*a)-(R*R);
        c=sqrt(c);
        c*=(2.0);
        double p=(a+b+c)/(2.0);
        double r=(p-a)*(p-b)*(p-c)/p;
        r=sqrt(r);
        r+=frc;
        cout<<"Case "<<T<<": ";
        if(n==2)r=R/(2.0);
        fxd(10);
        cout<<r<<"\n";
    }
    return 0;
}