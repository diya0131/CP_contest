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

ll pow(ll k, ll p) {
    ll q = 1;
    for (ll i = 0;i < p;i++) {
        q *= k;
    }
    return q;
}

void solve() {
    ll n, m, k, i, j, c, s, q, sx, sy, tx, ty, t, d, p;
    cin >> n >> m >> k;
    char ch;
    vector a(n + 1, vector(m + 1, 0LL));
    for (i = 1; i <= n; i++) {
        for (j = 1;j <= m;j++) {
            cin >> ch;
            a[i][j] = ch - '0';
        }
    }
    if (k == 1) {
        cin >> q;
        while (q--) {
            cin >> sx >> sy >> tx >> ty;
            cout << a[sx][sy] - a[tx][ty] << endl;
        }
        return;
    }
    bool inv = false;
    for (i = 1;i < n;i++) {
        for (j = 1;j < m;j++) {
            if (pow(a[i][j] - a[i + 1][j], k) + pow(a[i + 1][j] - a[i + 1][j + 1], k)
                != pow(a[i][j] - a[i][j + 1], k) + pow(a[i][j + 1] - a[i + 1][j + 1], k)) {
                    // cout<<i _ j _ "a"<<endl;
                inv = true;
                break;
            }
            if (pow(a[i][j + 1] - a[i][j], k) + pow(a[i][j] - a[i + 1][j], k)
                != pow(a[i][j + 1] - a[i + 1][j + 1], k) + pow(a[i + 1][j + 1] - a[i+1][j], k)) {
                // cout<<i _ j _ "b"<<endl;

                inv = true;
                break;
            }
        }
        if (inv) break;
    }

    if (!inv) {
        vector  dpx(n + 1, vector(m + 1, 0LL));
        for (i = 1;i <= n;i++) {
            for (j = 2;j <= m;j++) {
                dpx[i][j] = dpx[i][j - 1] + pow(a[i][j - 1] - a[i][j], k);
            }
        }
        vector  dpy(n + 1, vector(m + 1, 0LL));
        for (j = 1;j <= m;j++) {
            for (i = 2;i <= n;i++) {
                dpy[i][j] = dpy[i - 1][j] + pow(a[i - 1][j] - a[i][j], k);
            }
        }
        

        cin >> q;
        while (q--) {
            cin >> sx >> sy >> tx >> ty;
            cout << (dpx[sx][ty] - dpx[sx][sy]) + (dpy[tx][ty] - dpy[sx][ty]) << endl;
        }
        return;
    }

    cin >> q;
    while (q--) {
        cin >> sx >> sy >> tx >> ty;
        cout << "INVALID\n";
    }

}

int main() {
    // BOOST

    solve();

}