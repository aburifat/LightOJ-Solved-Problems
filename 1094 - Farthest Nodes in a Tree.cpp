#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll,ll> >adj[30010];
ll dis[30010];
bool visited[30010];

void init(){
    for(ll i=0;i<30005;i++){
        adj[i].clear();
        dis[i]=0;
        visited[i]=false;
    }
}

void bfs(ll s)
{
    ll len=adj[s].size();
    dis[s]=0;
    visited[s]=true;
    queue<ll>q;
    q.push(s);
    while(!q.empty()){
        s=q.front();
        q.pop();
        ll len=adj[s].size();
        for(ll i=0;i<len;i++){
            ll u=adj[s][i].first;
            if(visited[u]==false){
                visited[u]=true;
                q.push(u);
                dis[u]=dis[s]+adj[s][i].second;
            }
        }
    }
}

int main()
{
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        init();
        ll n;
        cin>>n;
        ll u, v, w;
        for(ll i=0;i<n-1;i++){
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        bfs(0);
        ll idx=0;
        for(ll i=0;i<n;i++){
            if(dis[i]>dis[idx])idx=i;
        }
        for(ll i=0;i<=n;i++){
            dis[i]=0;
            visited[i]=false;
        }
        bfs(idx);
        ll ans=0;
        for(ll i=0;i<n;i++){
            ans=max(ans,dis[i]);
        }
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}