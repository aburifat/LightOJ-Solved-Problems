#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[35][35][30];
string a,b;

void init(){
    for(ll i=0;i<35;i++){
        for(ll j=0;j<35;j++){
            for(ll k=0;k<30;k++)dp[i][j][k]=-1;
        }
    }
}

ll findLen(ll idx_a, ll idx_b, ll pre, ll len_a, ll len_b){
    if(idx_a>len_a||idx_b>len_b)return INT_MAX;
    if(idx_a==len_a&&idx_b==len_b)return 0;
    if(dp[idx_a][idx_b][pre]!=-1)return dp[idx_a][idx_b][pre];
    if(idx_a==len_a){
        dp[idx_a][idx_b][pre]=(1+findLen(idx_a,idx_b+1,(b[idx_b]-'A'),len_a,len_b));
    }else if(idx_b==len_b){
        dp[idx_a][idx_b][pre]=(1+findLen(idx_a+1,idx_b,(a[idx_a]-'A'),len_a,len_b));
    }else if(a[idx_a]==b[idx_b]){
        dp[idx_a][idx_b][pre]=(1+findLen(idx_a+1,idx_b+1,(b[idx_b]-'A'),len_a,len_b));
    }else{
        ll val1=(1+findLen(idx_a,idx_b+1,(b[idx_b]-'A'),len_a,len_b));
        ll val2=(1+findLen(idx_a+1,idx_b,(a[idx_a]-'A'),len_a,len_b));
        dp[idx_a][idx_b][pre]=min(val1,val2);
    }
    return dp[idx_a][idx_b][pre];
}

ll dp2[32][32][28][62];

void init2(){
    for(ll i=0;i<32;i++){
        for(ll j=0;j<32;j++){
            for(ll k=0;k<28;k++){
                for(ll l=0;l<62;l++)dp2[i][j][k][l]=-1;
            }
        }
    }
}

ll ctDp(ll idx_a, ll idx_b, ll pre, ll len, ll mx_len, ll len_a, ll len_b){
    if(idx_a>len_a||idx_b>len_b||len>mx_len)return 0;
    if(idx_a==len_a&&idx_b==len_b&&len==mx_len)return 1;
    if(dp2[idx_a][idx_b][pre][len]!=-1)return dp2[idx_a][idx_b][pre][len];
    if(idx_a==len_a){
        dp2[idx_a][idx_b][pre][len]=ctDp(idx_a,idx_b+1,(b[idx_b]-'A'),len+1,mx_len,len_a,len_b);
    }
    else if(idx_b==len_b){
        dp2[idx_a][idx_b][pre][len]=ctDp(idx_a+1,idx_b,(a[idx_a]-'A'),len+1,mx_len,len_a,len_b);
    }
    else if(a[idx_a]==b[idx_b]){
        dp2[idx_a][idx_b][pre][len]=ctDp(idx_a+1,idx_b+1,(a[idx_a]-'A'),len+1,mx_len,len_a,len_b);
    }else{
        ll val1=ctDp(idx_a,idx_b+1,(b[idx_b]-'A'),len+1,mx_len,len_a,len_b);
        ll val2=ctDp(idx_a+1,idx_b,(a[idx_a]-'A'),len+1,mx_len,len_a,len_b);
        dp2[idx_a][idx_b][pre][len]=val1+val2;
    }
    return dp2[idx_a][idx_b][pre][len];
}

int main(){
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        init();
        cin>>a>>b;
        ll len_a=a.size();
        ll len_b=b.size();
        ll len=findLen(0,0,0,len_a,len_b);
        init2();
        ll ct=ctDp(0,0,0,0,len,len_a,len_b);
        cout<<"Case "<<T<<": "<<len<<" "<<ct<<endl;
    }
    return 0;
}
