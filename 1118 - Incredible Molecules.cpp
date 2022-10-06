#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double PI=(2.0)*acos(0.0);
constexpr double frac=1e-9;

int main()
{
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        double x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        if(r1<r2){
            swap(r1,r2);
            swap(x1,x2);
            swap(y1,y2);
        }
        cout<<"Case "<<T<<": ";
        double difx=abs(x1-x2);
        double dify=abs(y1-y2);
        double d=sqrt((difx*difx)+(dify*dify));
        //cout<<"D : "<<d<<endl;
        if((r1+r2)<=d){
            double ans=0;
            cout<<fixed<<setprecision(10)<<ans<<"\n";
            continue;
        }else if((d+r2)<=r1){
            double ans=PI*r2*r2;
            cout<<fixed<<setprecision(10)<<ans<<"\n";
            continue;
        }
        //d+=frac;
        double x=abs((r1*r1)-(r2*r2)+(d*d));
        x/=((2.0)*d);
        double c1,c2;
        c1=abs((2.0)*acos(x/r1));
        c2=abs((2.0)*acos((d-x)/r2));
        double ans1,ans2,ans;
        ans1=abs((r1*r1)*(c1-sin(c1)));
        ans2=abs((r2*r2)*(c2-sin(c2)));
        ans=(ans1+ans2)/(2.0);
        cout<<fixed<<setprecision(10)<<ans<<"\n";
    }
    return 0;
}