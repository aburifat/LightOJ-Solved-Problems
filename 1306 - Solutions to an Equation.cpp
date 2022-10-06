#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exGCD(ll a, ll b, ll &x, ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll d=exGCD(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return d;
}

//Ax+By+C=0
ll countAll(ll a, ll b, ll c, ll x_min, ll x_max, ll y_min, ll y_max) {
    ll x,y; ll g=exGCD(a, b, x, y);
    if (a==0&&b==0) {
	if (c!=0) return 0;
	ll  ctVal=abs(x_max-x_min+1);
	ctVal*=abs(y_max-y_min+1);
	return ctVal;
    }
    else if (a==0) {
	if (c%b!=0) return 0;
	c = -c / b;
	if (y_min <= c && c <= y_max) 
return abs(x_max-x_min+1);
	return 0;
    }
    else if (b==0) {
	if (c%a!=0) return 0;
	c = -c / a;
	if (x_min <= c && c <= x_max)
 return abs(y_max-y_min+1);
	return 0;
    }
    if (c%g==0) {
	x*=(-c/g); y*=(-c/g);
	b/=g; a/=g;swap(a,b);
	double p=(x_min-x)/(double)a;
double q=(x_max-x)/(double)a;
	if(p>q)swap(p, q);
	x_min=ceil(p);x_max=floor(q);
	p=(y- y_min)/(double)b;
q=(y - y_max)/(double)b;
	if(p>q) swap(p,q);
	y_min=ceil(p);y_max=floor(q);
	x_min=max(x_min, y_min);
x_max=min(x_max, y_max);
	return max(0LL, x_max-x_min+1);
    }
    return 0;
}


int main()
{
    ll t;
    cin>>t;
    ll a, b, c, x1, x2, y1, y2;
     for(ll T=1;T<=t;T++){
        cin>>a>>b>>c>>x1>>x2>>y1>>y2;
        ll ans=countAll(a,b,c,x1,x2,y1,y2);
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
     }
    return 0;
}
