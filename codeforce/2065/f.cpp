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

vector < vector< int > > adj;

vector < bool > res;

int c=1;

void go(int k, int p, vector< int >& a){
    if(p!=-1 && a[k]==a[p]) res[a[k]]=1;
    for(int to :adj[k]){
        if(to!=p){
            go(to, k, a);
        }
    }
}

void go2(int k, int p, vector< int >& a, vector<int>& b){
    for(int to :adj[k]){
        if(b[a[to]]==c) res[a[to]]=1;
        else b[a[to]]=c;
    }
    c++;
    for(int to :adj[k]){
        if(to!=p){
            go2(to, k, a, b);
        }
    }
}


void solve() {
    int n, i, j, k, s, t, u, v;
    cin>>n;
    vector< int > a(n);
    vector< int > b(n, 0);
    adj.clear();
    adj.resize(n);
    res.assign(n, 0);
    for(i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    
    for(i=1;i<n;i++){
        cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    go(0, -1, a);
    go2(0, -1, a, b);
    for(i=0;i<n;i++){
        if(res[i]) cout<<'1';
        else cout<<'0';
    }
    cout<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}