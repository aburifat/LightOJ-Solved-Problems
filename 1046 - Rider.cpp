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
// Problem	: Rider
// Contest	: LightOJ
// URL		: https://lightoj.com/problem/rider
// Memory Limit : 64 MB
// Time Limit	: 1000 ms


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define F first
#define S second

ll dx[]={1,1,2,2,-1,-1,-2,-2};
ll dy[]={2,-2,1,-1,2,-2,1,-1};

//(x+1, y+2), (x+1, y-2), (x+2, y+1), (x+2, y-1), (x-1, y+2), (x-1, y-2), (x-2, y+1), (x-2, y-1)

ll goBabe(ll k, pair<ll,ll>s, pair<ll,ll>d, ll n, ll m){
	queue<pair<ll,pair<ll,ll>>>q;
	bool visited[n+5][m+5];
	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=m;j++)visited[i][j]=false;
	}
	q.push({0,s});
	visited[s.F][s.S]=true;
	ll ans=-1;
	while(!q.empty()){
		ll predis=q.front().F;
		s=q.front().S;
		q.pop();
		if(s.F==d.F&&s.S==d.S){
			ans=predis;
			break;
		}
		for(ll i=0;i<8;i++){
			ll x=s.F+dx[i];
			ll y=s.S+dy[i];
			if(x>=0&&x<n&&y>=0&&y<m&&visited[x][y]==false){
				q.push({predis+1,{x,y}});
				visited[x][y]=true;
			}
		}
	}
	if(ans!=-1){
		ans=(ans/k)+(ans%k!=0);
	}
	return ans;
}

int main(){
	ll t=1;
	cin>>t;
	for(ll T=1;T<=t;T++){
		ll n,m;
		cin>>n>>m;
		string s[n+5];
		ll ct=0;
		for(ll i=0;i<n;i++){
			cin>>s[i];
		}
		vector<pair<ll,ll>>riders;
		for(ll i=0;i<n;i++){
			for(ll j=0;j<m;j++){
				if(s[i][j]!='.'){
					ct++;
					riders.push_back({i,j});
				}
			}
		}
		
		cout<<"Case "<<T<<": ";
		vector<ll>possible;
		for(ll i=0;i<n;i++){
			for(ll j=0;j<m;j++){
				ll gone=0;
				ll tot_step=0;
				for(ll k=0;k<(ll)riders.size();k++){
					ll typ=s[riders[k].F][riders[k].S]-'0';
					ll step=goBabe(typ,riders[k],{i,j},n,m);
					if(step>=0){
						gone++;
						tot_step+=step;
					}else break;
				}
				if(gone==ct)possible.push_back(tot_step);
				
			}
		}
		sort(possible.begin(),possible.end());
		if(possible.size()>0)cout<<possible[0]<<endl;
		else cout<<"-1\n";
	}
	return 0;
}