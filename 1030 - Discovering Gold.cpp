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
// Problem	: Discovering Gold
// Contest	: LightOJ
// URL		: https://lightoj.com/problem/discovering-gold
// Memory Limit : 64 MB
// Time Limit	: 1000 ms

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double dp[110];
ll golds[110];
ll n;

void init(){
	for(ll i=0;i<110;i++)dp[i]=-1;
}

double getGold(ll idx){
	if(idx>=n)return 0;
	if(dp[idx]>=0)return dp[idx];
	ll mx_go=min((ll)6,n-idx-1);
	double prob=(double)1/(double)mx_go;
	double val=(double)golds[idx];
	for(ll i=idx+1;i<=idx+mx_go;i++){
		val+=(prob*getGold(i));
	}
	dp[idx]=val;
	return dp[idx];
}

int main(){
	ll t;
	cin>>t;
	for(ll T=1;T<=t;T++){
		init();
		cin>>n;
		for(ll i=0;i<n;i++){
			cin>>golds[i];
		}
		getGold(0);
		cout << fixed << setprecision(9);
		cout<<"Case "<<T<<": "<<dp[0]<<endl;
	}
	return 0;
}