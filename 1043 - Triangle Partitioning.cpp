#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double PI=(2.0)*acos(0.0);
double frc=0.000000001;
#define fxd(a) cout<<fixed<<setprecision(a)


double findArea(double a, double b, double c)
{
    double p=(a+b+c)/2.0;
    double area=p*(p-a)*(p-b)*(p-c);
    area=sqrt(area);
    return area;
}

int main()
{
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++)
    {
        double AB, AC, BC, res;
        cin>>AB>>AC>>BC>>res;
        double ABC=findArea(AB,AC,BC);
        double ADC=(ABC*res)/(res+1.0);
        double ans=ADC/ABC;
        ans=sqrt(ans);
        ans*=AB;
        ans+=frc;
        cout<<"Case "<<T<<": ";
        fxd(10);
        cout<<ans<<"\n";
    }
    return 0;
}