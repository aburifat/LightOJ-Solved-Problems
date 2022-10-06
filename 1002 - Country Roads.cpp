#include<bits/stdc++.h>
using namespace std;
typedef int ll;

vector<ll>graph[510];
ll weight[510][510];
ll mx_cost[510];
bool visited[510];

void init(){
    for(ll i=0;i<=500;i++){
        graph[i].clear();
        mx_cost[i]=-1;
        visited[i]=false;
        for(ll j=0;j<=500;j++){
            weight[i][j]=-1;
        }
    }
}

void add_to_graph(ll i, ll j, ll w)
{
    if(weight[i][j]==-1){
        graph[i].push_back(j);
        graph[j].push_back(i);
        weight[i][j]=w;
        weight[j][i]=w;
    }else{
        weight[i][j]=min(weight[i][j],w);
        weight[j][i]=min(weight[j][i],w);
    }
}

void calculate_max_cost(ll s)
{
    mx_cost[s]=0;
    priority_queue<pair<ll,ll> >pq;
    pq.push({0,s});
    while(!pq.empty()){
        ll node=pq.top().second;
        ll w=-pq.top().first;
        pq.pop();
        visited[node]=true;
        for(auto u:graph[node]){
            if(visited[u]==false){
                ll val=max(w,weight[node][u]);
                if((mx_cost[u]==-1)||(mx_cost[u]>val)){
                    mx_cost[u]=val;
                    pq.push({-mx_cost[u],u});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    ll n, m;
    for(ll T=1;T<=t;T++){
        init();
        cin>>n>>m;
        ll u,v,w,s;
        for(ll i=0;i<m;i++){
            cin>>u>>v>>w;
            add_to_graph(u,v,w);
        }
        cin>>s;
        calculate_max_cost(s);
        cout<<"Case "<<T<<":\n";
        for(ll i=0;i<n;i++){
            if(mx_cost[i]==-1){
                cout<<"Impossible\n";
            }else cout<<mx_cost[i]<<"\n";
        }
    }
    return 0;
}
