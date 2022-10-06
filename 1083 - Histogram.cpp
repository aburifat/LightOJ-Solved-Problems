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
// Problem	: Histogram
// Contest	: LightOJ
// URL		: https://lightoj.com/problem/histogram
// Memory Limit : 64 MB
// Time Limit	: 2000 ms


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MX 30030


ll arr[MX];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll t=1;
	cin>>t;
	for(ll T=1;T<=t;T++){
		ll ans=0;
		ll n;
		cin>>n;
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
		stack<ll>st;
		ll left[MX],right[MX];
		for(ll i=0;i<n;i++){
			while(!st.empty()){
				if(arr[st.top()]>=arr[i])st.pop();
				else break;
			}
			if(st.empty()){
				left[i]=0;
			}else{
				left[i]=(st.top())+1;
			}
			st.push(i);
		}
		while(!st.empty())st.pop();
		for(ll i=n-1;i>=0;i--){
			while(!st.empty()){
				if(arr[st.top()]>=arr[i])st.pop();
				else break;
			}
			if(st.empty()){
				right[i]=n-1;
			}else{
				right[i]=(st.top())-1;
			}
			st.push(i);
		}
		for(ll i=0;i<n;i++){
			ll val=abs(right[i]-left[i])+1;
			val*=arr[i];
			ans=max(ans,val);
		}
		cout<<"Case "<<T<<": "<<ans<<endl;
	}
	return 0;
}