#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ff first
#define ss second
#define PII pair < int, int >
#define PLL pair < ll, ll >

using namespace std;

void solve() {
    ll n, i, j, ma = 0, mi = 0, a = 0, b = 0, x, y;
    cin >> n;
    int a1[n], b1[n];
    for (i = 0;i < n;i++) cin >> a1[i];
    for (i = 0;i < n;i++) cin >> b1[i];
    for (i = 0;i < n;i++) {
        x = a1[i];
        y = b1[i];
        if (x == y) {
            if (x == -1) mi++;
            if (x == 1) ma++;
        } else {
            if (x > y) a += x;
            else b += y;
        }
    }

    if (max(a, b) - mi >= min(a, b) + ma) cout << min(a, b) + ma << endl;
    else {
        if (a + b + ma - mi < 0) cout << (a + b + ma - mi - 1) / 2 << endl;
        else cout << (a + b + ma - mi) / 2 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}