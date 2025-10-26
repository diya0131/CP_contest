#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = true;

void solve(){
    ll n, m, i, j, x, y;
    cin>>n>>x>>y;
    x--;
    y--;
    bool p = true;
    p=min(x, y)%2;
    
    for(i=0;i<min(x, y);i++) {
        if(p) cout<<"-1 ";
        else cout<<"1 ";
        p=!p;
    }
    for(i=min(x, y);i<=max(x, y);i++) cout<<1<<" ";
    p=true;
    for(;i<n;i++) {
        if(p) cout<<"-1 ";
        else cout<<"1 ";
        p=!p;
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}