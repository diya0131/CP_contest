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

void solve() {
    ll n, m, k, i, j, s=0;
    cin >> n >> m >> k;
    ll a[m];
    for (i = 0; i < m; i++) cin >> a[i];
    ll q[k];
    for (i = 0;i < k;i++) {
        cin >> q[i];
        s += q[i];
    }
    string tr(m, '1'), fl(m, '0');
    if (k == n - 1) {
        for (i = 0;i < m;i++) {
            if (a[i] == n * (n + 1) / 2 - s) cout << "1";
            else cout << "0";
        }
        cout<<endl;
    } else {
        if (k == n) cout << tr << endl;
        else cout << fl << endl;
    }
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}