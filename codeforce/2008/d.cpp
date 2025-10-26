#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define ss second
#define _ <<" "<<

using namespace std;

const bool te = 0;
vector < ll > a, par, cnt;
string s;

ll getP(ll k) {
    if (par[k] != k) {
        ll p = getP(par[k]);
        par[k] = p;
    }
    return par[k];
}

void join(ll x, ll y) {
    ll px = getP(x);
    ll py = getP(y);
    par[px] = py;
    cnt[py] += cnt[px];
}

void go(ll k) {
    while (getP(k) != getP(a[k])) {
        join(k, a[k]);
        k=a[k];
    }
}

void solve() {
    ll n, i, j, k, l, r;
    cin >> n;
    a.resize(n);
    par.resize(n);
    cnt.resize(n);
    for (i = 0;i < n;i++) {
        cin >> a[i];
        a[i]--;
        par[i] = i;
    }
    cin >> s;
    for(i=0;i<n;i++){
        cnt[i]=1 - s[i] + '0';
    }
    for (i = 0;i < n;i++) {
        if (getP(i)==i) {
            go(i);
        }
    }
    for(i=0;i<n;i++){
        k=getP(i);
        // cout<<i _ k _ cnt[k]<<endl;
        cout<<cnt[k]<<" ";

    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}