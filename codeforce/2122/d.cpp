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

void solve() {
    ll n, m, i, j, u, v, s, t, w, sz, k, to, tmx;
    cin>>n>>m;
    vector<vector<ll>>adj(n);
    for(i=0;i<m;i++){
        cin>>u>>v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    priority_queue < pair < ll, pair < ll, ll > > > pq;
    pair < ll, pair < ll, ll > > pr;
    vector< pair < ll, ll > > dp(n, {LLONG_MAX, LLONG_MAX});
    vector < ll > mx(n, LLONG_MAX);
    vector < ll > mxw(n, LLONG_MAX);
    pq.push({0, {0, 0}});
    while(!pq.empty()){
        pr = pq.top();
        pq.pop();
        i = pr.ss.ss;
        t = -pr.ff;
        w = -pr.ss.ff;
        // cout<< i _ t _ w _ dp[i].ff _ dp[i].ss<<endl;
        // if(t > mx[i] || (dp[i].ff <= t && dp[i].ss <= w)) continue;
        if(t >= mx[i] && w - t > mxw[i]) continue;
        cout<<i _ t _ w<<endl;
        mx[i] = min(mx[i], t);
        mx[i] = min(mx[i], w - t);
        dp[i] = min(dp[i], {t, w});
        // if(i==n-1) break;
        sz = adj[i].size();
        tmx = 0;
        for(j=0;j<sz;j++){
            to = adj[i][j];
            if(t%sz > j) k = sz - t%sz + j;
            else k = j - t%sz;
            // cout<<"*" _  to _ t+k+1 _ w+k _ mx[to] _ mxw[to] <<endl;
            // if( t+k+1 > mx[to] || (dp[to].ff <= t+k+1 && dp[to].ss <= w+k)) continue;
            
            // if( t+k+1 >= mx[to] && w+k >= mxw[to]) continue;
            // cout<<"--\n";
            tmx = max(k, tmx);
            pq.push({-(t+k+1), {-(w+k), to } } );
        }
        // mxw[i] = min(mxw[i], w+tmx);
        // if(mx[i]==LLONG_MAX) mx[i] = tmx;
    }
    cout<<dp[n-1].ff _ dp[n-1].ss<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}