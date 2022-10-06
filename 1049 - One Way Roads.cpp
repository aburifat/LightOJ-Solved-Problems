#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll,ll> >adj[110];
bool visited[110];
ll dis[110];

void init(){
    for(ll i=0;i<110;i++)adj[i].clear();
}

void cl(){
    memset(visited,false,sizeof(visited));
    memset(dis,-1,sizeof(dis));
}

void bfs(ll ss, ll val){
    visited[ss]=true;
    dis[ss]=val;
    queue<ll>q;
    q.push(ss);
    while(!q.empty()){
        ll s=q.front();
        q.pop();
        for(auto nd:adj[s]){
            ll u=nd.first;
            ll w=nd.second;
            if(s==ss&&u==1)continue;
            if(visited[u]==false){
                visited[u]=true;
                dis[u]=dis[s]+w;
                q.push(u);
                //cout<<"s : "<<s<<" "<<dis[s]<<endl;
                //cout<<"u : "<<u<<" "<<dis[u]<<endl;
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
        ll a, b, c;
        for(ll i=0;i<n;i++){
            cin>>a>>b>>c;
            adj[a].push_back({b,(ll)0});
            adj[b].push_back({a,c});
        }
        cl();
        ll s=adj[1][0].first;
        ll val=adj[1][0].second;
        bfs(s,val);
        ll ans=dis[1];
        cl();
        s=adj[1][1].first;
        val=adj[1][1].second;
        bfs(s,val);
        ans=min(ans,dis[1]);
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}
