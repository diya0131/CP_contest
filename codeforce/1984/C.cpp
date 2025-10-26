#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

ll mod = 998244353;

void solve() {
    ll n, i, j, k, s, t, mi, ma, mic, mac, x, y, x1, y1, mi1, ma1;
    cin >> n;
    ll a[n];
    for (i = 0;i < n;i++) cin >> a[i];
    mi = 0; ma = 0;
    mic = 1; mac = 0;
    if (a[0] < 0) {
        ma = -a[0];
        mi = a[0];
        mac = 1;
        mic = 1;
    } else {
        ma = a[0];
        mi = a[0];
        mac = 2;
        mic = 2;
    }
    for (i = 1;i < n;i++) {
        x = mac;
        y = mic;
        x1 = 0;
        y1 = 0;
        ma1 = max(abs(ma + a[i]), abs(mi + a[i]));
        mi1 = mi + a[i];

        if (ma1 == ma + a[i]) x1 = (x1 + x) % mod;
        if (ma1 == abs(ma + a[i])) x1 = (x1 + x) % mod;


        if (mi1 == ma + a[i]) y1 = (y1 + x) % mod;
        if (mi1 == abs(ma + a[i])) y1 = (y1 + x) % mod;


        if (mi != ma) {
            if (ma1 == mi + a[i]) x1 = (x1 + y) % mod;
            if (ma1 == abs(mi + a[i])) x1 = (x1 + y) % mod;
            if (mi1 == mi + a[i]) y1 = (y1 + y) % mod;
            if (mi1 == abs(mi + a[i])) y1 = (y1 + y) % mod;
        }

        mac = x1;
        mic = y1;

        ma = ma1;
        mi = mi1;
        // cout<<ma _ mi _ mac _ mic<<endl;
    }
    cout << mac << endl;

}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}