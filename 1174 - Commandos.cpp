/**      BU_Excalibur      **/
/** University of Barishal **/
/**  BFS  **/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

constexpr ll MX=110;
bitset<MX>visited;
vector<ll>adj[MX];
ll dis[MX];
ll sto[MX];

void bfs(ll s) {
    queue<ll>q;
    visited[s]=true;
    q.push(s);
    while(!q.empty()) {
        s=q.front();
        q.pop();
        ll len=adj[s].size();
        for(auto u:adj[s]) {
            if(!visited[u]) {
                visited[u]=true;
                dis[u]=dis[s]+1;
                q.push(u);
            }
        }
    }
}

int main() {

    /***************************************/
    // Site Name        : LightOJ
    // Problem No/ID    : 1174
    /***************************************/
    // your code here   :


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin>>t;
    ll node,edge;
    for(ll T=1; T<=t; T++) {
        cin>>node>>edge;
        for(ll i=0; i<=node; i++) {
            visited[i]=false;
            adj[i].clear();
            dis[i]=0;
            sto[i]=0;
        }
        for(ll i=0; i<edge; i++) {
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll s,d;
        cin>>s>>d;
        bfs(s);
        for (ll i=0;i<=node;i++){
            sto[i]=dis[i];
            dis[i]=0;
            visited[i]=false;
        }
        bfs(d);
        ll ans=0;
        for(ll i=0;i<node;i++){
            ans=max(ans,sto[i]+dis[i]);
        }
        cout<<"Case "<<T<<": "<<ans<<"\n";
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************///
}

/*
input:
4

4
4
0 1
0 2
0 3
2 3
1 2

7
8
0 1
0 2
2 3
3 4
4 5
3 6
3 0
4 0
0 5

8
10
0 1
1 2
0 3
2 4
4 5
2 6
5 7
5 0
0 4
3 4
0 6

5
6
0 1
0 2
0 3
1 4
2 4
3 4
0 4

output:
3
5
6
2

*/
