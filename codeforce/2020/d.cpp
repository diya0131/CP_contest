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

vector < ll > par;
ll n, res;

ll getp(ll k){
    if(par[k]==k) return k;
    ll p=getp(par[k]);
    par[k]=p;
    return par[k];
}

void join(ll u, ll v){
    ll pu=getp(u);
    ll pv=getp(v);
    if(pu!=pv) res--;
    par[pu]=pv;
}

void solve() {
    ll m, k, a, d, s, i, j, c;
    cin>>n>>m;
    vector< vector< ll >  > path(10, vector< ll >(n+1, 0));
    
    while(m--){
        cin>>a>>d>>k;
        path[d-1][a-1]++;
        path[d-1][a+d*k-1]--;
    }
    par.resize(n);
    for(i=0;i<n;i++) par[i]=i;
    res=n;
    for(i=0;i<10;i++){
        for(j=0;j+i+1<n;j++){
            if(path[i][j]>0){
                join(j, j+i+1);
            }
            path[i][j+i+1]+=path[i][j];
        }
    }
    cout<<res<<endl;

}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}