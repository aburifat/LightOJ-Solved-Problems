#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>adj[505];
ll parent[505];
ll dis[505];
bool visited[505];

void init(){
    for(ll i=0;i<505;i++){
        adj[i].clear();
        parent[i]=-1;
        dis[i]=LONG_MAX;
        visited[i]=false;
    }
}
void cln(){
    for(ll i=0;i<505;i++){
        parent[i]=-1;
        dis[i]=LONG_MAX;
        visited[i]=false;
    }
}

int main(){
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        init();
        ll n,m;
        cin>>n>>m;
        ll u,v;
        for(ll i=0; i<m; i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll ans=LONG_MAX;
        for(ll i=0;i<n;i++){
            cln();
            queue<ll>q;
            q.push(i);
            visited[i]=true;
            parent[i]=-1;
            dis[i]=0;
            while(!q.empty()){
                ll s=q.front();
                q.pop();
                ll len=adj[s].size();
                for(auto u:adj[s]){
                    if(visited[u]==false){
                        q.push(u);
                        visited[u]=true;
                        dis[u]=dis[s]+1;
                        parent[u]=s;
                    }else if((parent[s]!=u)&&(parent[u]!=s)){
                        ans=min(ans,dis[s]+dis[u]+1);
                    }
                }
            }
        }
        cout<<"Case "<<T<<": ";
        if(ans==LONG_MAX)cout<<"impossible\n";
        else cout<<ans<<"\n";
    }
    return 0;
}