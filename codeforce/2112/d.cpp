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

void go(vector<vector<int>>&adj, int nd, int p, bool dir){
    for(int to:adj[nd]){
        if(to==p) continue;
        if(!dir) cout<<to _ nd<<endl;
        else cout<<nd _ to<<endl;
        go(adj, to, nd, !dir);
    }
}

void solve() {
    ll n, i, j, u, v;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(i=1;i<n;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(i=1;i<=n;i++){
        if(adj[i].size()==2){
            cout<<"YES\n";
            cout<<adj[i][0] _ i<<endl;
            cout<<i _ adj[i][1]<<endl;
            go(adj, adj[i][0], i, 1);
            go(adj, adj[i][1], i, 0);
            return;
        }
    }
    cout<<"NO\n";
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}