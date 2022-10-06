#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll PI=(2.0)*acos(0.0);

double getTriArea(double a, double b, double c)
{
    double p=(a+b+c)/(2.0);
    double area=p*(p-a)*(p-b)*(p-c);
    area=sqrt(area);
    return area;
}

int main()
{
    ll t;
    cin>>t;
    double a,b,c,d;
    for(ll T=1;T<=t;T++){
        cin>>a>>b>>c>>d;
        if(a<c)swap(a,c);
        double x,y,z;
        x=a-c;
        y=b;
        z=d;
        double triArea=getTriArea(x,y,z);
        double h=triArea*(2.0);
        h/=x;
        double ans=triArea+(h*c);
        cout<<"Case "<<T<<": ";
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}