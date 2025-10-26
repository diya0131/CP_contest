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
    ll n, i, j, k, s, l, r;
    cin >> n;
    vector < pair < ll, ll > > a(n);
    vector < int > b(2 * n + 1, 0), c(2 * n + 1);
    for (i = 0;i < n;i++) {
        cin >> a[i].ff >> a[i].ss;
        if (a[i].ff == a[i].ss) b[a[i].ff]++;
    }
    s = 0;
    for (i = 0;i <= 2 * n;i++) {
        if(b[i]) s++;
        c[i] = s;
    }
    for (i = 0;i < n;i++) {
        if(a[i].ff==a[i].ss){
            if(b[a[i].ff]==1) cout<<1;
            else cout<<0;
            continue;
        }
        if (c[a[i].ss] - c[a[i].ff - 1] == a[i].ss - a[i].ff + 1) cout << 0;
        else cout << 1;
    }
    cout << endl;

}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}