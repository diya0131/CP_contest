#include<bits/stdc++.h>
#include<chrono>
#include <random>
#include <unordered_set>
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
    ll n, m, i, j, k, s, u, v, idx=0, sz, x, y;
    cin>>n>>m;
    vector < unordered_set<ll> > adj(n); 
    vector < vector < ll > > moves(2*max(n, m));
    vector < ll > move(3);
    unordered_set < ll >::iterator it;
    for(i=0;i<m;i++){
        cin>>u>>v;
        u--;
        v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    bool empty=true;
    for(i=0;i<n;i++){
        sz = adj[i].size();
        if(sz%2) empty = 0;
        while(sz>=2){
            it=(adj[i].rbegin());
            u=*it;
            adj[i].erase(it);
            it=(adj[i].rbegin());
            v=*it;
            adj[i].erase(it);
            if(adj[u].count(v)>0){
                adj[u].erase(v);
                adj[v].erase(u);
            } else {
                adj[u].insert(v);
                adj[v].insert(u);
            }
            adj[v].erase(i);
            adj[u].erase(i);
            move[0]=i;
            move[1]=u;
            move[2]=v;
            moves[idx]=move;
            idx++;
            sz-=2;
        }
    }
    
    if(!empty){
        for(i=0;i<n;i++){
            if(adj[i].size()==1){
                x = i;
                y=*adj[i].begin();
                break;
            }
        }
        
        vector < bool > is(n, 0);
        is[x]=1;
        is[y]=1;
        for(i=0;i<n;i++){
            if(!is[i]){
                if(adj[i].size()==0){
                    move[0]=x;
                    move[1]=y;
                    move[2]=i;
                    moves[idx]=move;
                    idx++;
                    is[i]=1;
                    x=i;
                } else {
                    k=*adj[i].begin();
                    move[0]=x;
                    move[1]=i;
                    move[2]=k;
                    moves[idx]=move;
                    idx++;
                    is[k]=1;
                    is[i]=1;
                }
            }
        }
    }
    
    
    cout<<idx<<endl;
    for(i=0;i<idx;i++){
        cout<<moves[i][0]+1 _ moves[i][1]+1 _ moves[i][2]+1<<endl;
    }
    return;
}

int main() {
    BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}