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

vector<vector<pair <ll,ll>>>adj;

void solve() {
    ll n, m, i, u, v, w, j, k, t, nd;
    cin>>n>>m;
    adj.clear();
    adj.resize(n);
    for(i=0;i<m;i++){
        cin>>u>>v>>w;
        u--; v--;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    vector <pair <ll,ll>>c(n, {-1, -1});
    priority_queue < pair <ll, pair< ll, ll > > > pq;
    pair <ll, pair< ll, ll > > pr;
    pq.push({0, {-LLONG_MAX, 0}});
    while(!pq.empty()){
        pr = pq.top();
        pr.ff = - pr.ff;
        pr.ss.ff = - pr.ss.ff;
        pq.pop();
        nd = pr.ss.ss;
        // cout<<nd _ pr.ff <<endl;
        if(c[nd].ff!=-1) continue;
        c[nd] = {pr.ff, pr.ss.ff};
        for(auto to:adj[nd]){
            if(c[to.ff].ff!=-1) continue;
            pq.push({ -max(pr.ff, to.ss), {-min(pr.ss.ff, to.ss), to.ff}});
        }
    }
    // for(i=0;i<n;i++){
    //     cout<<i _ c[i].ff _ c[i].ss<<endl;
    // }
    // cout<<c[n-1].ff _ c[n-1].ss
    ll res = c[n-1].ff + c[n-1].ss;
    for(i=0;i<n;i++){
        res = min(res, max(c[n-1].ff, c[i].ff) + min(c[n-1].ss, c[i].ss));
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