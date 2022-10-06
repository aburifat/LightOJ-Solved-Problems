#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dx[]= {1,-1,0,0,1,-1,-1,1};
ll dy[]= {0,0,1,-1,1,1,-1,-1};

bool visited[100][100];
ll label[100][100];
ll dis[100][100];
ll n,m;

ll bfs(ll x, ll y) {
    queue<pair<ll,ll> >q;
    visited[x][y]=true;
    dis[x][y]=0;
    q.push({x,y});
    while(!q.empty()) {
        pair<ll,ll>par=q.front();
        q.pop();
        if(label[par.first][par.second]==1) {
            return dis[par.first][par.second];
        }
        for(ll i=0; i<4; i++) {
            ll ux=par.first+dx[i];
            ll uy=par.second+dy[i];
            if((!visited[ux][uy])&&(label[ux][uy]!=2)) {
                dis[ux][uy]=dis[par.first][par.second]+1;
                q.push({ux,uy});
                visited[ux][uy]=true;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    for(ll T=1; T<=t; T++) {
        for(ll i=0; i<100; i++) {
            for(ll j=0; j<100; j++) {
                label[i][j]=0;
            }
        }
        cin>>n>>m;
        char tmp;
        vector<pair<ll,ll> >a;
        for(ll i=0; i<n; i++) {
            for(ll j=0; j<m; j++) {
                cin>>tmp;
                if(tmp=='#'||tmp=='m')label[i][j]=2;
                else if(tmp=='h')label[i][j]=1;
                else if(tmp=='a'||tmp=='b'||tmp=='c')a.push_back({i,j});
            }
        }
        ll len=a.size();
        ll ans=0;
        for(ll i=0; i<len; i++) {
            ll x=a[i].first;
            ll y=a[i].second;
            for(ll i=0; i<100; i++) {
                for(ll j=0; j<100; j++) {
                    dis[i][j]=0;
                    visited[i][j]=false;
                }
            }
            ll val=bfs(x,y);
            ans=max(ans,val);
        }
        cout<<"Case "<<T<<": "<<ans<<"\n";
    }

    return 0;
}
