#include<bits/stdc++.h>

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

const bool TEST = 0;

int bln=20;
vector < vector < int > > adj;
vector < ll > a, b, dep; //deepest leaf, fathers deepest leaf without me haha, depth
vector < vector < ll > > bl, anc;

void dfs(ll k, ll p, ll lvl){
    dep[k]=lvl;
    ll mx=0, he=0, mxi=-1, ti, tmx;
    for(ll to:adj[k]){
        if(to!=p){
            dfs(to, k, lvl+1);
            if(a[to]>mx){
                mx=a[to];
                mxi=to;
            }
        }
    }
    a[k]=1+mx;
    ti=mxi;
    tmx=mx;
    mx=0;
    for(ll to:adj[k]){
        if(to!=p && to!=ti){
            mx=max(mx, a[to]);
            b[to]=tmx-lvl;
        }
    }
    // cout<<"- " _ k _ ti _ mx _ lvl<<endl;
    if(ti!=-1) b[ti]=mx-lvl;
}

void build(ll k, ll p){
    test<<k _ p <<endl;
    bl[k][0]=max(b[k], b[p]);
    anc[k][0]=p;
    for(int i=1;i<bln;i++){
        bl[k][i]=max(bl[k][i-1], bl[anc[k][i-1]][i-1]);
        anc[k][i]=anc[anc[k][i-1]][i-1];
    }
    for(int to : adj[k]){
        if(p!=to) build(to, k);
    }
}

void solve() {
    ll n, i, j, k, s, u, v, q, d, p;
    cin>>n;
    adj.clear();
    adj.resize(n);
    bl.assign(n, vector < ll > (bln,0));
    anc.assign(n, vector < ll > (bln,0));
    dep.resize(n);
    a.assign(n, 0);
    b.assign(n, 0);
    for(i=1;i<n;i++){
        cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, -1, 0);
    build(0, 0);
    for(i=0;i<n;i++){
        test<<i _ dep[i] _ a[i] _ b[i]<<endl;
    }
    for(i=0;i<n;i++){
        for(j=0;j<5;j++) test<<bl[i][j]<<" ";
        test<<endl;
    }
    cin>>q;
    while(q--){
        cin>>u>>v;
        u--;
        v--;
        p=dep[u];
        s=a[u]-p-1;
        i=0;
        d=p;
        test<<p _ s _ d<<endl;
        if(v==0 && s<b[u]){
            s=b[u];
            d=p+1;
        } else{
            while(v>0){
                if(v%2){
                
                    test<<":" _ u _ v _ bl[u][i]<<endl;
                    s=max(s, bl[u][i]);
                    u=anc[u][i];
                    test<<":" _ s _ d<<endl;
                }
                i++;
                v/=2;
            }
        }
        cout<<s+p<<" ";
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