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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;

const bool TEST = 0;

vector < vector < ll >> adj;
vector < bool > isng, sf;

ll res, lf;

void dfs_ng(ll k, ll p){
    bool islf = false;
    if(adj[k].size()==1) {
        lf++;
        islf=1;
    }
    for(ll to:adj[k]){
        if(to==p) continue;
        dfs_ng(to, k);
        if(adj[to].size()==1) islf=1;
    }
    sf[k]=!islf;
    if(islf){
        for(ll to:adj[k]){
            if(to==p) continue;
            if(adj[to].size()>1) isng[to]=1;
        }
    }
}
pair < ll, ll > dfs(ll k, ll p){
    ll x =0, y=0, c=0;
    pair < ll, ll > pr;
    queue < pair<ll,ll> > q;
   
    for(ll to:adj[k]){
        if(to==p) continue;
        pr = dfs(to, k);
        if(!sf[to]){
            test<<"HEYYYY" _ k _ to _ sf[to] _ pr.ss<<endl;
            res+=pr.ss;
        }
        q.push(pr);
        x+=pr.ff;
        y+=pr.ss;
    }
    test<<k<<"---------------------\n";
    while(!q.empty()){
        pr = q.front();
        q.pop();
        test<<"get" _ pr.ff _ pr.ss _ pr.ff * (y - pr.ss)<<endl;
        res += pr.ff * (y - pr.ss);
    }
    
    test<<res _ x _ y<<endl;
    
    if(sf[k]) {
        test<<"safe" _ x<<endl;
        res+=x;
    }
    if(isng[k]) {
        x++;
    }
    if(sf[k]) {
        y++;
    }
    test<<res<<endl;
    return {x, y};

}

void solve() {
    ll n, i, j, k, s, t, x, y;
    cin>>n;
    adj.clear();
    adj.resize(n);
    isng.clear();
    isng.resize(n,0);
    sf.clear();
    sf.resize(n,0);
    for(i=1;i<n;i++){
        cin>>x>>y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    res=0;
    lf=0;
    ll rt = 0;
    if(n<=2){
        cout<<0<<endl;
        return;
    }
    while(adj[rt].size()==1) rt++;
    dfs_ng(rt, -1);

    dfs(rt, -1);
    test<<"res: ";
    cout<<lf * (n-lf)+res<<endl;

}   

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}