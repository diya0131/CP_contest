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

vector < vector< ll > > adj;
vector< ll > cnt, mxd;

ll dfs(ll k, ll p, ll d){
    cnt[d]++;
    ll mx=d, t;
    for(ll to : adj[k]){
        if(to!=p){
            t=dfs(to, k, d+1);
            mx=max(mx, t);
        }
    }
    mxd[mx]++;
    return mx;
}


void solve() {
    ll n, u, v, i, s, k, t, mx=-1;
    cin>>n;
    adj.clear();
    adj.resize(n);
    for(i=1;i<n;i++){
        cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cnt.assign(n, 0);
    mxd.assign(n, 0);
    dfs(0, -1, 0);
    k=n;
    vector < ll > pref(n+1);
    s=0;
    pref[n]=0;
    
    for(i=n-1;i>=0;i--){
        s+=cnt[i];
        pref[i]=s;
    }
    // for(int num:cnt) cout<<num <<" ";
    // cout<<endl;
    // for(int num:pref) cout<<num <<" ";
    // cout<<endl;
    // for(int num:mxd) cout<<num <<" ";
    // cout<<endl;
    ll mxda=0;
    for(i=1;i<n;i++){
        mxda+=mxd[i-1];
        // cout<<i _ n - pref[i+1] - mxd[i-1] _ pref[i+1] _ mxda<<endl;
        mx=max(mx, n - pref[i+1] - mxda);
    }
    cout<<n-mx<<endl;;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}