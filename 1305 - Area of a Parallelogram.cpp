#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++)
    {
        ll ax,ay,bx,by,cx,cy,dx,dy;
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        dx=ax+cx-bx;
        dy=ay+cy-by;
        ll area=abs(((ax*by)+(bx*cy)+(cx*ay))-((bx*ay)+(cx*by)+(ax*cy)));
        cout<<"Case "<<T<<": ";
        cout<<dx<<" "<<dy<<" "<<area<<endl;
    }
    return 0;
}









