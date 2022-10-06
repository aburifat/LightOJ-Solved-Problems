#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double PI=(2.0)*acos(0.0);
constexpr double frac=1e-10;

double getDis(double ax, double ay, double bx, double by)
{
    double xx=ax-bx;
    xx*=xx;
    double yy=ay-by;
    yy*=yy;
    double dis=xx+yy;
    dis=sqrt(dis);
    //dis+=frac;
    return dis;
}

double getAngle(double a, double r)
{
    double ang=(r*r);
    ang+=ang;
    ang-=(a*a);
    ang/=((2.0)*r*r);
    ang=acos(ang);
    return ang;
}

int main()
{
    ll t;
    cin>>t;
    double ox,oy,ax,ay,bx,by;
    for(ll T=1;T<=t;T++){
        cin>>ox>>oy>>ax>>ay>>bx>>by;
        double ab=getDis(ax,ay,bx,by);
        double r=getDis(ax,ay,ox,oy);
        double ans;
        if(ab<=frac&&r<=frac){
            ans=0;
        }else{
            double A=getAngle(ab,r);
            ans=r*A;
        }
        cout<<"Case "<<T<<": ";
        cout<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}





