#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define CASE(T) cout<<"Case "<<T<<": "

string grid[15];
vector<pair<ll,ll> >foods;
vector<vector<ll> >val;
vector<vector<bool> >visited;
ll n;

ll dx[]={0,0,1,-1};
ll dy[]={-1,1,0,0};

void BFS(ll x, ll y){
    visited[x][y]=true;
    val[x][y]=0;
    queue<pair<ll,ll> >q;
    pair<ll,ll>pr;
    q.push({x,y});
    while(!q.empty()){
        pr=q.front();
        q.pop();
        x=pr.first;
        y=pr.second;
        for(ll i=0;i<4;i++){
            ll x_n=x+dx[i];
            ll y_n=y+dy[i];
            if(x_n>=0&&y_n>=0&&x_n<n&&y_n<n){
                if(!visited[x_n][y_n]&&grid[x_n][y_n]!='#'){
                    visited[x_n][y_n]=true;
                    val[x_n][y_n]=val[x][y]+1;
                    q.push({x_n,y_n});
                }
            }
        }
    }
}

int main(){
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        ll ans=0,ck=0,alpha_ct=0;
        foods.assign(30,{-1,-1});
        cin>>n;
        for(ll i=0;i<n;i++)cin>>grid[i];
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(grid[i][j]>='A'&&grid[i][j]<='Z'){
                    alpha_ct++;
                    ll idx=grid[i][j]-'A';
                    foods[idx]={i,j};
                    grid[i][j]='#';
                }
            }
        }
        if(alpha_ct<=1)goto prnt;
        for(ll i=0;i<25;i++){
            if(ck)break;
            if((foods[i].first==-1&&foods[i].second==-1)||(foods[i+1].first==-1&&foods[i+1].second==-1))continue;
            ll x_s=foods[i].first;
            ll y_s=foods[i].second;
            ll x_e=foods[i+1].first;
            ll y_e=foods[i+1].second;
            grid[x_s][y_s]='.';
            grid[x_e][y_e]='.';
            visited.assign(n,vector<bool>(n,false));
            val.assign(n,vector<ll>(n,-1));
            BFS(x_s,y_s);
            if(val[x_e][y_e]==-1)ck=1;
            else ans+=val[x_e][y_e];
        }
        prnt:
        CASE(T);
        (ck)? cout<<"Impossible\n" : cout<<ans<<"\n";
    }
    return 0;
}