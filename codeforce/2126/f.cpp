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

map < ll, map<ll, ll> > mp;

void go(ll k, ll par, vector<vector<pair<ll, ll>>>& adj, vector<ll>& a){
    for(pair<ll,ll> to : adj[k]){
        mp[k][a[to.ff]]+=to.ss;
        if(to.ff==par) continue;
        go(to.ff, k, adj, a);
    }
    
}

void solve() {
    ll n, q, i, j, s, t, k, u, v, c, x, res=0;
    mp.clear();
    cin>>n>>q;
    map < ll, map< ll, ll> > mp;
    vector<vector<pair<ll, ll>>>adj(n);
    vector<ll>a(n);
    for(i=0;i<n;i++) cin>>a[i];
    for(i=1;i<n;i++){
        cin>>u>>v>>c;
        u--; v--;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
        if(a[u]!=a[v]) res += c;
    }
    go(0, -1, adj, a);
    while(q--){
        cin>>v>>x;
        
        v--;
        if(mp[v].find(a[v])!=mp[v].end()){
            res += mp[v][a[v]];
        }
        if(mp[v].find(x)!=mp[v].end()){
            res -= mp[v][x];
        }
        a[v] = x;
        cout<<res<<endl;
    }
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}