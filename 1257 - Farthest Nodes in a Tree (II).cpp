#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll,ll> >adj[30010];
bool visited[30010];
ll dis[30010][3];

void init()
{
    for(ll i=0;i<30010;i++)adj[i].clear();
}

void bfs(ll s,ll id){
    dis[s][id]=0;
    visited[s]=true;
    queue<ll>q;
    q.push(s);
    while(!q.empty()){
        s=q.front();
        q.pop();
        for(auto u:adj[s]){
            ll v=u.first;
            ll w=u.second;
            if(visited[v]==false){
                visited[v]=true;
                dis[v][id]=dis[s][id]+w;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    ll n;
    for(ll T=1;T<=t;T++){
        init();
        cin>>n;
        ll u,v,w;
        for(ll i=0;i<n-1;i++){
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        memset(visited,false,sizeof(visited));
        memset(dis,-1,sizeof(dis));
        bfs(0,0);
        ll st=0;
        ll val=dis[st][0];
        for(ll i=1;i<n;i++){
            if(dis[i][0]>val){
                st=i;
                val=dis[i][0];
            }
        }
        memset(visited,false,sizeof(visited));
        bfs(st,1);
        ll ed=0;
        val=dis[ed][1];
        for(ll i=0;i<n;i++){
            if(dis[i][1]>val){
                ed=i;
                val=dis[i][1];
            }
        }
        memset(visited,false,sizeof(visited));
        bfs(ed,2);
        cout<<"Case "<<T<<":\n";
        ll ans;
        for(ll i=0;i<n;i++){
            if(i==st||i==ed)ans=val;
            else ans=max(dis[i][1],dis[i][2]);
            cout<<ans<<"\n";
        }
    }
    return 0;
}