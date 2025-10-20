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

vector < vector < ll > > adj;

ll leaf, safe, cnt, both;

pair <bool, bool> dfs(ll k, ll p){
    ll s=0, c=0;
    bool sf = true;
    pair < bool, bool > pr;
    if(adj[k].size()==1){
        leaf++;
        return {false, false};
    }
    for(ll to : adj[k]){
        if(to==p) continue;
        pr = dfs(to, k);
        sf = sf & pr.ss;
        if(pr.ss){
            s++;
            if(pr.ff) {
                c++;
                // cout<<"both" _ k<<endl;
            }
        }
    }
    if(sf) {
        // cout<<"safe" _ k<<endl;
        safe++;
    }
    else {
        cnt+=s;
        both+=c;
    }
    
    return {sf, true};
}

void solve() {
    ll n, i, k, t, s=0, x, y;
    cin>>n;
    adj.clear();
    adj.resize(n);
    for(i=1;i<n;i++){
        cin>>x>>y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    leaf=0;
    safe=0;
    cnt=0;
    both =0;
    if(n<=2){
        cout<<0<<endl;
        return;
    }
    for(i=0;i<n;i++){
        if(adj[i].size()>1) break;
    }
    dfs(i, -1);
    
    cout<< i _ leaf _ cnt _ safe _ both _ endl;
    cout << leaf * (n - leaf) + cnt * safe - both<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}