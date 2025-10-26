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

vector< ll > par, parx;


ll getP(ll x){
    if(par[x]==x) return x;
    ll p = getP(par[x]);
    par[x]=p;
    return p;
}

void join(ll x, ll y){
    ll px = getP(x), py = getP(y);
    if(px<py) swap(px, py);
    par[px]=py;
}

ll getPx(ll x){
    if(parx[x]==x) return x;
    ll p = getPx(parx[x]);
    parx[x]=p;
    return p;
}

void joinx(ll x, ll y){
    ll px = getPx(x), py = getPx(y);
    if(px<py) swap(px, py);
    parx[px]=py;
}



void solve() {
    ll n, m1, m2, i, j, k, s=0, u, v;
    cin>>n>>m1>>m2;
   
    par.resize(n);
    parx.resize(n);
    for(i=0;i<n;i++){
        par[i]=i;
        parx[i]=i;
    }
    vector < pair < ll, ll > > a(m1);
    for(i=0;i<m1;i++){
        cin>>u>>v;
        a[i]={u, v};
    }
    while(m2--){
        cin>>u>>v;
        join(u-1, v-1);
    }
    for(i=0;i<m1;i++){
        
        u = a[i].ff-1;
        v = a[i].ss-1;
        if(getP(u)==getP(v)) joinx(u, v);
        else s++;
    }
    // cout<<s<<endl;
    for(i=0;i<n;i++){
        if(getP(i)!=getPx(i)) {
            // cout<<getP(i) _ getPx(i) _ i<<endl;
            s++;
            joinx(getPx(i), getP(i));
        }
    }
    cout<<s<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}