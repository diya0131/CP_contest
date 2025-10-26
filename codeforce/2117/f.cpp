#include<bits/stdc++.h>
#include<chrono>
#include <random>

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define BOOST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define test if(TEST) cout

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const bool TEST = 0;

int c, mn;

const ll M = 1e9+7;


void solve() {
    int n, i, j, k, s, u, v;
    cin>>n;
    vector<vector<int>>adj(n);
    for(i=1;i<n;i++){
        cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    mn=INT_MAX;
    int c=0;
    if(adj[0].size()>2){
        cout<<0<<endl;
        return;
    }
    if(adj[0].size()==2) c=1;
    for(i=1;i<n;i++){
        if(adj[i].size()>3){
            cout<<0<<endl;
            return;
        }
        if(adj[i].size()==3) c++;
    }
    
    // cout<<c<<endl;
    if(c>=2) {
        cout<<0<<endl;
        return;
    }
    if(c==0){
        ll res =1;
        for(i=0;i<n;i++){
            res = (res*2)%M;
        }
        cout<<res<<endl;
        return;
    }
    int x=-1, y=-1;
    for(i=1;i<n;i++){
        if(adj[i].size()==1){
            if(x==-1) x=i;
            else y=i;
        }
    }
    int xc=1, yc=1, p;
    p=x;
    x=adj[x][0];
    while(adj[x].size()!=3 && x!=0){
        
        xc++;
        if(adj[x][0]==p) {
            p=x;
            x = adj[x][1];}
        else {
            p=x;
            x=adj[x][0];
        }
    }
    p=y;
    y=adj[y][0];
    while(adj[y].size()!=3 && y!=0){
        yc++;
        if(adj[y][0]==p) {
            p=y;
            y = adj[y][1];
        }
        else {
            p=y;
            y=adj[y][0];
        }
    }
    ll res =3;
    // cout<<xc _ yc<<endl;
    if(xc==yc) {
        res=1;
        n-=2*xc-1;}
    else n-=2*min(xc, yc)+1;
    
    for(i=0;i<n;i++){
        res = (res*2)%M;
    }
    cout<<res<<endl;

}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}