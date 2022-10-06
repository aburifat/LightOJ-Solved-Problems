#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mx=20010;

vector<ll>graph[mx];
ll MX_N=1;
bool visited[mx];
bool ii[mx];

void init(){
    for(ll i=0;i<=20000;i++){
        graph[i].clear();
        visited[i]=false;
        ii[i]=false;
    }
    MX_N=1;
}

void add_edge(ll u, ll v){
    //cout<<"Graph "<<u<<" "<<v<<endl;
    graph[u].push_back(v);
    graph[v].push_back(u);
}

ll bfs(ll s){
    ll ct[2];
    ct[1]=1;
    ct[0]=0;
    queue<pair<ll,ll> >q;
    q.push({s,1});
    visited[s]=true;
    while(!q.empty()){
        s=q.front().first;
        ll wt=q.front().second;
        q.pop();
        //cout<<"Edge Parent: "<<s<<endl;
        for(auto u:graph[s]){
            //cout<<"Edge :"<<s<<" "<<u<<endl;
            if(visited[u]==false){
                visited[u]=true;
                if(wt==1){
                    ct[0]++;
                	q.push({u,0});
                }else{
                    ct[1]++;
                	q.push({u,1});
                }
                
            }
        }
    }
    //cout<<ct[0]<<" "<<ct[1]<<endl;
    return max(ct[0],ct[1]);
}

int main(){
    ll t;
    cin>>t;
    ll n;
    for(ll T=1;T<=t;T++){
        init();
        cin>>n;
        ll u,v;
        for(ll i=0;i<n;i++){
            cin>>u>>v;
            ii[u]=true;
            ii[v]=true;
            MX_N=max(MX_N,max(u,v));
            add_edge(u,v);
        }
        ll ans=0;
        for(ll i=1;i<=MX_N;i++){
            if(visited[i]==false&&ii[i]==true){
                ll ct=bfs(i);
                ans+=ct;
            }
        }
        cout<<"Case "<<T<<": "<<ans<<"\n";
    }
    return 0;
}