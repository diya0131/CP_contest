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

vector< int > col;

bool dfs(int k, vector < vector< int > >& adj, int c){
    if(col[k]!=-1){
        if(col[k]!=c) return false;
        return true;
    }
    col[k]=c;
    for(int to: adj[k]){
        if(!dfs(to, adj, (c+1)%2)) return false;
    }
    return true;
}

void solve() {
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(0);
    int n, s1, s2, k, i, j, u, v, m, c1, c2;
    cin>>n>>s1>>s2;
    s1--;
    s2--;
    vector < vector< int >> adj1(n), adj2(n);
    cin>>m;
    while(m--){
        cin>>u>>v;
        u--;
        v--;
        adj1[u].pb(v);
        adj1[v].pb(u);
    }
    cin>>m;
    while(m--){
        cin>>u>>v;
        u--;
        v--;
        adj2[u].pb(v);
        adj2[v].pb(u);
    }
    col.clear();
    col.resize(n, -1);
    bool bl;
    bl = dfs(s1, adj1, 0);
    if(bl){
        if(col[s2]!=0){
            bl = dfs(s2, adj2, 0);
            if(bl){
                cout<<-1<<endl;
                return;
            }
        }
    }
    
    priority_queue < pair <int, pair < int , int > > > pq;
    vector < vector< bool > > is(n, vector < bool> (n, false));
    pair <int, pair < int , int > > pr;
    pq.push({0, {s1, s2}});
    while(!pq.empty()){
        pr = pq.top();
        pq.pop();
        // cout<<pr.ff _ pr.ss.ff _ pr.ss.ss<<endl;
        if(is[pr.ss.ff][pr.ss.ss]) continue;
        is[pr.ss.ff][pr.ss.ss]=1;
        for(int& to1: adj1[pr.ss.ff]){
            for(int& to2: adj2[pr.ss.ss]){
                if(to1==to2 && pr.ss.ff == pr.ss.ss) {
                    cout<<-pr.ff<<endl;
                    return;
                }
                pq.push({pr.ff-abs(to1-to2), {to1, to2}});
            }
        }

    }
    cout<<-1<<endl;

}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}