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
// Problem	: A Dangerous Maze
// Contest	: LightOJ
// URL		: https://lightoj.com/problem/a-dangerous-maze
// Memory Limit : 64 MB
// Time Limit	: 1000 ms

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MX 110

ll values[MX],probs[MX];

int main(){
	ll t;
	cin>>t;
	for(ll T=1;T<=t;T++){
		ll up=0,bottom=0;
		ll n;
		cin>>n;
		bottom=n;
		for(ll i=0;i<n;i++){
			ll tmp;
			cin>>tmp;
			if(tmp<0)bottom--;
			up+=abs(tmp);
		}
		if(bottom!=0){
			ll gcd=__gcd(up,bottom);
			up/=gcd;
			bottom/=gcd;
		}
		cout<<"Case "<<T<<": ";
		if(bottom!=0)cout<<up<<"/"<<bottom<<"\n";
		else cout<<"inf\n";
	}
	return 0;
}