#include<bits/stdc++.h>
#include<random>
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

vector< vector< int > >edges;
vector< int > par, dead;
vector< pair<int, int> > f, g;
vector< set< pair < int, int > > >child;



pair<int, int> dfs(int nd, int p){
    par[nd]=p;
    int t;
    child[nd].insert({0, nd});
    child[nd].insert({0, nd});
    pair < int, int > pr, mx={0, nd};
    for(int to:edges[nd]){
        if(to==p) continue;
        pr = dfs(to, nd);
        child[nd].insert(pr);
        mx = max(mx, pr);

    }
    mx.ss++;
    return mx;
}

void update(int nd, int ch){
    if(nd==-1 || dead[nd]) return;
    pair<int, int> pr;
    pr = f[ch];
    pr.ff++;
    child[nd].erase(pr);
    f[ch] = *prev(child[ch].end());
    g[ch] = *prev(prev(child[ch].end()));
    pr = f[ch];
    pr.ff++;
    child[nd].insert(pr);
    update(par[nd], nd);
}


void solve() {
    ll n, u, v, i, j, s, k, t;
    pair < int , pair < int, int > > pr;
    cin>>n;
    s=n;
    edges.clear();
    par.clear();
    dead.clear();
    child.clear();
    edges.resize(n);
    par.resize(n);
    dead.resize(n, 0);
    child.resize(n);

    f.resize(n);
    g.resize(n);

    for(i=1;i<n;i++){
        cin>>u>>v;
        u--;
        v--;
        edges[u].pb(v);
        edges[v].pb(u);
    }

    dfs(0, -1);
    priority_queue < pair < int, int > > pq;
    pair < int, int > hd, mx;
    for(int i=0;i<n;i++){
        f[i] = *prev(child[i].end());
        g[i] = *prev(prev(child[i].end()));
        pq.push({f[i].ff+g[i].ff+1, i});
    }
    while(!pq.empty()){
        hd = pq.top();
        pq.pop();
        if(dead[hd.ss]) continue;
        cout<<hd.ff _ f[hd.ss].ss _ g[hd.ss].ss<<" ";
        t = f[i].ss;
        while(t!=hd.ss){
            dead[t]=1;
            t = par[t];
        }
        t = g[i].ss;
        while(t!=hd.ss){
            dead[t]=1;
            t = par[t];
        }
        dead[hd.ss]=1;
        if(par[hd.ss]!=-1 && dead[par[hd.ss]]==0){
            mx = f[hd.ss];
            mx.ff++;
            child[par[hd.ss]].erase(mx);
            update(par[par[hd.ss]], par[hd.ss]);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}