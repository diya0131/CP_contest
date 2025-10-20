#include<bits/stdc++.h>
#include<chrono>
// #include<random>

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

const ll M = 998244353;

vector < vector < ll > > adj;

ll inv(ll k){
    ll p = M-2, q=k, res=1;
    while(p>0){
        if(p%2) res = (res*q)%M;
        p/=2;
        q=(q*q)%M;
    }
    return res;
}

void solve() {
    ll n, i, j, u, v, k, s, res=0, x;
    cin>>n;
    adj.clear();
    adj.resize(n);
    for(i=1;i<n;i++){
        cin>>u>>v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector < ll > p(n, -1), prob(n);
    queue < ll > q, leaf;
    q.push(0);
    p[0]=0;
    while(!q.empty()){
        k=q.front();
        q.pop();
        for(ll to: adj[k]){
            if(p[to]==-1){
                if(adj[to].size()==1){
                    leaf.push(to);
                }
                q.push(to);
                p[to]=k;
            }
        }
    }
    p[0]=-1;
    vector < bool > vis(n, 0);
   
    prob[0]=1;
    vis[0]=1;
    while(!leaf.empty()){
        k = leaf.front();
        leaf.pop();
        s=0;
        while(!vis[k]){
            q.push(k);
            vis[k]=1;
            k=p[k];
            s++;
        }
        x = prob[k]*inv(s)%M;
        u=0;
        while(!q.empty()){
            k=q.front();
            q.pop();
            prob[k]=u;
            u=(u+x)%M;
        }
    }
    for(i=0;i<n;i++){
        cout<<prob[i]<<" ";
    }
    cout<<endl;
}   

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}