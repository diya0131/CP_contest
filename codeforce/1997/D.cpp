#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = false;

vector < ll > a;
vector < vector < ll > > path;

ll dfs(ll nd, ll p){
    if(path[nd].size()==1 && nd!=0){
        return a[nd];
    }
    ll mi=-1;
    for(int i=0;i<path[nd].size();i++){
        if(path[nd][i]!=p){
            if(mi==-1) mi = dfs(path[nd][i], nd);
            else mi = min(mi, dfs(path[nd][i], nd));
        }
    }
    if(mi==-1) mi = 0;
    if(nd==0){
        return a[nd]+mi;
    }
    if(a[nd]<mi){
        return (a[nd]+mi)/2;
    } else return mi;
}

void solve(){
    ll n, k, i, j;
    cin>>n;
    a.clear();
    a.resize(n);
    path.clear();
    path.resize(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=1;i<n;i++){
        cin>>k;
        path[k-1].pb(i);
        path[i].pb(k-1);
    }

    cout<<dfs(0, -1)<<endl;

    
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}