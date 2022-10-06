#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MX 200010

//Basic Graph
ll node,edge;
vector<ll>adj[MX];
bool visited[MX];
bool idxOne=false;

//Connected Components
vector<ll>compList[MX];

//Bridge & Articulation Point
ll timeIn[MX],timeLow[MX];
ll timer;
bitset<MX>AP;
map<pair<ll,ll>,ll>bridge;
vector<ll>apList;
vector<pair<ll,ll> >bridgeList;

//Topological Sort Component
vector<ll>topSortList;

//Strongly Connected Component
vector<ll>revAdj[MX];
vector<ll>sccList[MX];

//Initiate Basic Graph
void initAdj(){
    for(ll i=0;i<MX;i++)adj[i].clear();
}
void initVisited(){
    for(ll i=0;i<MX;i++)visited[i]=false;
}
void initGraph(){
    initAdj();
    initVisited();
}

//Initiate Connected Component
void initConComp(){
    for(ll i=0;i<MX;i++)compList[i].clear();
}

//Initiate Bridge Cutpoint
void initAPBridge(){
    AP.reset();
    apList.clear();
    bridge.clear();
    bridgeList.clear();
    for(ll i=0;i<MX;i++){
        timeIn[i]=-1;
        timeLow[i]=-1;
    }
}

//Initiate Topological Sort
void initTopSort(){
    topSortList.clear();
}

//Initiate Reverse Adjacent List
void initRevAdj(){
    for(ll i=0;i<MX;i++)revAdj[i].clear();
}

//Initiate Strongly Connected Component
void initSCC(){
    initTopSort();
    initRevAdj();
    for(ll i=0;i<MX;i++)sccList[i].clear();
}

//Directed Edges
void dirEdge(ll u, ll v)
{
    adj[u].push_back(v);
}

//Undirected Edges OK
void unDirEdge(ll u, ll v)
{
    dirEdge(u,v);
    dirEdge(v,u);
}

//Directed SCC Edges
void SCCEdge(ll u, ll v){
    dirEdge(u,v);
    revAdj[v].push_back(u);
}

//DFS to find single CC OK
void compDFS(ll s,ll idx) {
    visited[s]=true ;
    compList[idx].push_back(s);
    for (auto u:adj[s]) {
        if (!visited[u]){
        	visited[u]=true ;
            compDFS(u,idx);
        }
    }
}

//Get all CC and number of CC OK
ll conComp(){
	ll ctComp=0;
    ll idx_st=0,idx_end=node;
    if(idxOne)idx_st++,idx_end++;
    for(ll i=idx_st;i<idx_end;i++){
        if(!visited[i]){
            compDFS(i,ctComp);
            ctComp++;
        }
    }
    return ctComp;
}

//Add Cutpoint OK
void addAP(ll v){
    if(!AP[v]){
        AP[v]=1;
        apList.push_back(v);
    }
}

//Add Bridge OK
void addBridge(ll v, ll to){
    if(!bridge[{v,to}]&&!bridge[{to,v}])bridgeList.push_back({v,to});
    bridge[{v,to}]=1;
    bridge[{to,v}]=1;
}

//DFS to Find Cutpoints & Bridges in a CC OK
void apBridgeDFS(ll v, ll p=-1){
    visited[v]=true;
    timeIn[v]=timeLow[v]=timer++;
    ll children=0;
    for(ll to:adj[v]){
        if(to==p)continue;
        if(visited[to]){
            timeLow[v]=min(timeLow[v],timeIn[to]);
        }else{
            apBridgeDFS(to,v);
            timeLow[v]=min(timeLow[v],timeLow[to]);
            if(timeLow[to]>=timeIn[v]&&p!=-1)addAP(v);
            if(timeLow[to]>timeIn[v])addBridge(v,to);
            ++children;
        }
    }
    if(p==-1&&children>1)addAP(v);
}

//find All Cutpoints & Bridges OK
void apBridge(){
    timer=0;
    ll idx_st=0,idx_end=node;
    if(idxOne)idx_st++,idx_end++;
    for(ll i=idx_st;i<idx_end;i++){
        if(!visited[i]){
            apBridgeDFS(i);
        }
    }
}
//Topological Sort DFS
void topSortDFS(ll s){
    visited[s]=true;
    for(auto u:adj[s]){
        if(!visited[u]){
            topSortDFS(u);
        }
    }
    topSortList.push_back(s);
}

//Topological Sort
void topSort(){
    for(ll i=0;i<node;i++){
        if(!visited[i])topSortDFS(i);
    }
    reverse(topSortList.begin(),topSortList.end());
}

//Strongly Connected Component DFS
void sccDFS(ll s, ll idx){
    visited[s]=true;
    sccList[idx].push_back(s);
    for(auto u:revAdj[s]){
        if(!visited[u])sccDFS(u,idx);
    }
}

//Stringly Connected Component
void SCC(){
    ll ctSCC=0;
    topSort();
    for(ll i=0;i<MX;i++)visited[i]=false;
    for(ll i=0;i<node;i++){
        ll s=topSortList[i];
        if(!visited[s]){
            sccDFS(s,ctSCC);
            ctSCC++;
        }
    }
}


int main(){
	ll t;
	cin>>t;
	for(ll T=1;T<=t;T++){
		initGraph();
        initAPBridge();
		cin>>node;
		//if(node<=0)continue;
		for(ll i=0;i<node;i++){
			ll idx;
			cin>>idx;
			string s;
			cin>>s;
			s.erase(0,1);
			ll len=s.size();
			s.erase(len-1,1);
			len=stoi(s);
			ll u;
			for(ll j=0;j<len;j++){
				cin>>u;
				unDirEdge(idx,u);
			}
		}
		apBridge();
		cout<<"Case "<<T<<":"<<endl;
		ll ans=bridgeList.size();
		cout<<ans<<" critical links"<<endl;
		for(ll i=0;i<ans;i++){
			ll a=bridgeList[i].first;
			ll b=bridgeList[i].second;
			if(a>b)swap(a,b);
			bridgeList[i]={a,b};
		}
		sort(bridgeList.begin(),bridgeList.end());
		for(ll i=0;i<ans;i++){
			ll a=bridgeList[i].first;
			ll b=bridgeList[i].second;
			cout<<a<<" - "<<b<<endl;
		}
	}
	return 0;
}