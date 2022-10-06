#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double PI=(2.0)*acos(0.0);

double getAngle(double a, double b, double c)
{
    double ang=(b*b);
    ang+=(c*c);
    ang-=(a*a);
    ang/=((2.0)*b*c);
    ang=acos(ang);
    return ang;
}

double getSector(double angle,double redious)
{
    double sec=angle*redious*redious;
    sec/=(2.0);
    return sec;
}

int main()
{
    ll t;
    cin>>t;
    double r1,r2,r3;
    for(ll T=1;T<=t;T++){
        cin>>r1>>r2>>r3;
        double a,b,c;
        a=r1+r2;
        b=r1+r3;
        c=r2+r3;
        double A,B,C;
        A=getAngle(a,b,c);
        B=getAngle(b,a,c);
        C=getAngle(c,a,b);
        double secA,secB,secC;
        secA=getSector(A,r3);
        secB=getSector(B,r2);
        secC=getSector(C,r1);
        double ABC=a*b*sin(C);
        ABC/=(2.0);
        double ans=ABC-(secA+secB+secC);
        cout<<"Case "<<T<<": ";
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}