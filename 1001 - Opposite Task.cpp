#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t){
        int a;
        cin>>a;
        int b=0;
        if(a>10){
            b=a-10;
            a=10;
        }
        cout<<b<<" "<<a<<endl;
        t--;
    }
    return 0;
}
