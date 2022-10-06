#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll word[30][30][30];
bool forbidden[30][30][30];

ll dx[]={0,0,0,0,1,-1};
ll dy[]={0,0,1,-1,0,0};
ll dz[]={1,-1,0,0,0,0};

void BFS(ll x, ll y, ll z){
    queue<pair<ll,pair<ll,ll> > >q;
    pair<ll,pair<ll,ll> >pr;
    q.push({x,{y,z}});
    while(!q.empty()){
        pr=q.front();
        q.pop();
        x=pr.first;
        y=pr.second.first;
        z=pr.second.second;
        for(ll i=0;i<6;i++){
            ll x_n=(x+dx[i]+26)%26;
            ll y_n=(y+dy[i]+26)%26;
            ll z_n=(z+dz[i]+26)%26;
            if(!forbidden[x_n][y_n][z_n]){
                if(word[x_n][y_n][z_n]==-1){
                    word[x_n][y_n][z_n]=word[x][y][z]+1;
                    q.push({x_n,{y_n,z_n}});
                }
            }
        }
    }
}

int main(){
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        for(ll i=0;i<30;i++){
            for(ll j=0;j<30;j++){
                for(ll k=0;k<30;k++){
                    word[i][j][k]=-1;
                    forbidden[i][j][k]=false;
                }
            }
        }
        string start,end;
        cin>>start>>end;
        ll m;
        cin>>m;
        for(ll M=0;M<m;M++){
            string a,b,c;
            cin>>a>>b>>c;
            ll len_a=a.size();
            ll len_b=b.size();
            ll len_c=c.size();
            for(ll i=0;i<len_a;i++){
                for(ll j=0;j<len_b;j++){
                    for(ll k=0;k<len_c;k++){
                        forbidden[a[i]-'a'][b[j]-'a'][c[k]-'a']=true;
                    }
                }
            }
        }
        if(!forbidden[start[0]-'a'][start[1]-'a'][start[2]-'a']){
            word[start[0]-'a'][start[1]-'a'][start[2]-'a']=0;
            BFS(start[0]-'a',start[1]-'a',start[2]-'a');
        }
        cout<<"Case "<<T<<": "<<word[end[0]-'a'][end[1]-'a'][end[2]-'a']<<"\n";
    }
    return 0;
}