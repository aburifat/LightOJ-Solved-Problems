#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>adj[1010];
ll visited[1010];

void init()
{
    for(ll i=0;i<1010;i++){
        adj[i].clear();
        visited[i]=false;
    }
}

void clr(){
    for(ll i=0;i<1010;i++){
        visited[i]=false;
    }
}

int main()
{
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        init();
        ll k,n,m;
        cin>>k>>n>>m;
        ll tmp;
        vector<ll>nodes;
        map<ll,ll>mp;
        nodes.push_back(0);
        for(ll i=0;i<k;i++){
            cin>>tmp;
            if(!mp[tmp]){
                mp[tmp]=nodes.size();
                nodes.push_back(tmp);
            }
        }
        ll len=nodes.size();
        ll u,v;
        for(ll i=0; i<m; i++){
            cin>>u>>v;
            adj[v].push_back(u);
        }
        ll visitCt[1010][len+5];
        for(ll i=0;i<1010;i++){
            for(ll j=0;j<=len;j++)visitCt[i][j]=0;
        }
        ll s;
        for(ll i=1;i<=n;i++){
            clr();
            queue<ll>q;
            q.push(i);
            if(mp[i])visitCt[i][mp[i]]=1;
            while(!q.empty()){
                s=q.front();
                q.pop();
                for(auto nd:adj[s]){
                    if(visited[nd]==false){
                        q.push(nd);
                        visited[nd]=true;
                        if(mp[nd])visitCt[i][mp[nd]]=1;
                    }
                }
            }
        }
        ll ans=0;
        len=nodes.size();
        for(ll i=1;i<=n;i++){
            ll ct=0;
            for(ll j=1;j<len;j++){
                ct+=visitCt[i][j];
            }
            if(ct==(len-1))ans++;
        }
        cout<<"Case "<<T<<": ";
        cout<<ans<<"\n";
    }
    return 0;
}