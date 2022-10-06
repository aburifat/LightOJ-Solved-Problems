#include <bits/stdc++.h>
using namespace std;

int t[4*100005];

void build(int a[], int v, int tl, int tr){
	if(tl==tr){
		t[v]=a[tl];
	}else{
		int tm = (tl + tr)/2;
		build(a, v*2, tl, tm);
		build(a, v*2+1, tm+1, tr);
		t[v] = min(t[v*2],t[v*2+1]);
	}
}

int q(int v, int tl, int tr, int l, int r){
	if(l>r){
		return INT_MAX;
		}
	if(tl==l&&tr==r){
		return t[v];
		}
	int tm = (tl+tr)/2;
	return min(q(v*2,tl,tm,l,min(r,tm)), q(v*2+1,tm+1,tr,max(tm+1,l),r));
}
 
int main()
{
	int t;
	cin>>t;
	for(int j=1; j<=t; j++){
		cout<<"Case "<<j<<":"<<endl;
		int a[100005];
		int n, m;
		cin>>n>>m;
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		build(a,1,1,n);
		int l, r;
		for(int i=1;i<=m;i++){
			cin>>l>>r;
			int ans = q(1,1,n,l,r);
			cout<<ans<<endl;
		}
	}
	return 0;
}
 
