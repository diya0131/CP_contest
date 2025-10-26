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
    int n, i, j, s = 0, k;
    bool t, p;
    cin >> n;
    t = false;
    p = false;
    vector < int > a(n);
    for (i = 0;i < n;i++) {
        cin >> a[i];
        if(a[i]!=0) p = 1;
    }
    for (i = 0;i < n;i++) {
        if (a[i] != 0) break;
    }
    for (j = n - 1;j >= i;j--) {
        if (a[j] != 0) break;
    }
    for (int l = i;l <= j;l++) {
        if (a[l] == 0) {
            t = 1;
        }
        if (k != 0) p = 1;
    }
    if (p == 0) {
        cout << 0 << endl;
        return;
    }
    if (t) cout << 2 << endl;
    else cout << 1 << endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}