// /*******Bismillahir-Rahmanir-Rahim**********/
// 
// Name         : Abu Rifat Muhammed Al Hasib
// Institution  : University of Barisal, Bangladesh
// Github       : https://github.com/abu-rifat
// website	: https://aburifat.com
// 
// Codeforces   : https://codeforces.com/profile/ARMaster
// lightoj      : https://lightoj.com/user/abu-rifat
// AtCoder      : https://atcoder.jp/users/aburifat
// codechef     : https://www.codechef.com/users/aburifat
// SPOJ         : https://www.spoj.com/users/abu_rifat
// UvaOJ        : https://uhunt.onlinejudge.org/id/889274
// 
// facebook     : https://facebook.com/AbuRifatM
// linkedin     : https://www.linkedin.com/in/aburifat
// Email        : rifat.cse4.bu@gmail.com
// 		  armalhasib@gmail.com
// 		  abu.rifat.m@gmail.com
// 
// Problem	: Wavio Sequence
// Contest	: LightOJ
// URL		: https://lightoj.com/problem/wavio-sequence
// Memory Limit : 64 MB
// Time Limit	: 2000 ms


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



vector<ll> LISLen(vector<ll>arr){
	vector<ll>emp;
	if(arr.size()==0)return emp;
	vector<ll>tail(arr.size(),0);
	vector<ll>lens(arr.size(),1);
	ll len=1;
	tail[0]=arr[0];
	for(ll i=1;i<(ll)arr.size();i++){
		auto b=tail.begin();
		auto e=tail.begin()+len;
		auto it=lower_bound(b,e,arr[i]);
		if(it==tail.begin()+len){
			tail[len++]=arr[i];
			lens[i]=len;
		}
		else{
			*it=arr[i];
			ll idx=it-tail.begin();
			lens[i]=idx+1;
		}
	}
	return lens;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	for(ll T=1;T<=t;T++){
		ll n;
		cin>>n;
		vector<ll>arr(n,0);
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
		vector<ll>left=LISLen(arr);
		reverse(arr.begin(),arr.end());
		vector<ll>right=LISLen(arr);
		ll ans=1;
		for(ll i=0;i<n;i++){
			ll val=min(left[i],right[n-i-1]);
			val*=2;
			val--;
			ans=max(ans,val);
		}
		cout<<"Case "<<T<<": "<<ans<<endl;
	}
	return 0;
}


