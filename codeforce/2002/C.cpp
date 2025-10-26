#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = false;

void solve() {
    ll n, m, k, i, j, x, y, x1, x2, x3, x4;
    cin >> n;
    pair< ll, ll > pr[n];
    for (i = 0;i < n;i++) {
        cin >> x >> y;
        pr[i] = { x, y };
    }
    cin >> x1 >> x2 >> x3 >> x4;
    ll t = abs(x1 - x3) * abs(x1 - x3) + abs(x2 - x4) * abs(x2 - x4);
    for (i = 0;i < n;i++) {
        x1 = pr[i].ff;
        x2 = pr[i].ss;
        k = abs(x1 - x3) * abs(x1 - x3) + abs(x2 - x4) * abs(x2 - x4);
        if (k <= t) {
            // cout<<k _ t _ i<<endl;
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}