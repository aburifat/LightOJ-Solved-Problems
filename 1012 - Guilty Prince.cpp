#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool visited[25][25];
ll val[25][25];

ll n,m;

ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

///land,initpos=0,water=1;

void bfs(ll x,ll y)
{
    queue<pair<ll,ll> >q;
    q.push({x,y});
    visited[x][y]=true;
    while(!q.empty()){
        pair<ll,ll>s=q.front();
        q.pop();
        for(ll i=0;i<4;i++){
            ll ux=s.first+dx[i];
            ll uy=s.second+dy[i];
            if(ux<0||ux>=n||uy<0||uy>=m)continue;
            if(!visited[ux][uy]&&val[ux][uy]==0){
                visited[ux][uy]=true;
                q.push({ux,uy});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        cin>>m>>n;
        char c;
        ll ix=0,iy=0;
        for(ll i=0;i<n; i++){
            for(ll j=0;j<m; j++){
                cin>>c;
                if(c=='#')val[i][j]=1;
                else{
                    val[i][j]=0;
                    if(c=='@'){
                        ix=i;
                        iy=j;
                    }
                }
            }
        }
        for(ll  i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                visited[i][j]=false;
            }
        }
        bfs(ix,iy);
        ll ans=0;
        for(ll  i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(visited[i][j]==true) ans++;
            }
        }
        cout<<"Case "<<T<<": "<<ans<<"\n";
    }
    return 0;
}
