
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

const int N = 300;

vector < vector < ll > > path;

vector < vector < ll > > dp;

pair < ll, ll > dfs(ll k, ll par){
    vector < ll > res(N+1, 0);

    if(path[k].size()==1 && k!=0){
        return ;
    }
    pair < ll, ll > pr;
    ll i, j, s=0, t;
    for(i=0;i<path[k].size();i++){
        if(path[k][i]!=par){
            pr=dfs(path[k][i], k);
        }
    }
}

void solve() {
    ll n, m, i, j, x, s = 0, k, u, v;
    cin >> n;
    path.clear();
    path.resize(n);
    dp.clear();
    dp.resize(n);
    for (i = 1;i < n;i++) {
        cin>>u>>v;
        u--;
        v--;
        path[u].pb(v);
        path[v].pb(u);
    }
    dfs(0 ,-1);

}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}