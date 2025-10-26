#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = true;

ll cnt;

void check(vector < ll >& p, vector < ll >& par, vector < ll >& isl, vector < bool >& is, ll k) {
    test<<"ch" _ k <<endl;
    ll i;
    bool can = true;
    if (p[k] != 1) {
        if (par[p[k]] != p[k / 2]) can = false;
    }
    if (!isl[k]) {
        test<<(p[k] != par[p[2 * k]]) _ (p[k] != par[p[2 * k + 1]])<<endl;
        if (p[k] != par[p[2 * k]]) can = false;
        if (p[k] != par[p[2 * k + 1]]) can = false;
    }
    test<<can _ cnt<<endl;
    if (can) {
        if (!is[k]) {
            cnt++;
        }
    } else {
        if (is[k]) {
            cnt--;
        }
    }
    is[k]=can;
    test<<can _ cnt<<endl;
}

void solve() {
    ll n, m, k, i, j, x, y, q, t;
    cin >> n >> q;
    bool can;
    vector < ll > par(n + 1), isl(n + 1, 1);
    
    par[1] = -1;
    for (i = 2;i <= n;i++) {
        cin >> k;
        isl[k] = 0;
        par[i] = k;
       
    }

    vector < ll > p(n + 1);
    vector < bool > is(n + 1, 0);
    for (i = 1;i <= n;i++) cin >> p[i];
    cnt = 0;
    for (i = 1;i <= n;i++) {
        check(p, par, isl, is, i);
    }
    test << cnt << endl;
    while (q--) {
        cin >> x >> y;
        t = p[x];
        p[x] = p[y];
        p[y] = t;
        check(p, par, isl, is, x);
        if (isl[p[x]] > 0 && 2*x+1<=n) {
            check(p, par, isl, is, 2 * x);
            check(p, par, isl, is, 2 * x + 1);
        }
        check(p, par, isl, is, y);
        if (isl[p[y]] > 0 && 2*y+1<=n) {
            check(p, par, isl, is, 2 * y);
            check(p, par, isl, is, 2 * y + 1);
        }
        if (cnt == n) {
            cout << "YES\n";
        } else cout << "NO\n";
    }

    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}