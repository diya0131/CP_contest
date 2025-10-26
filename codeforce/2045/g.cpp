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
    ll n, m, k, i, j, c, s, q, sx, sy, tx, ty, t, x, y;
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
    if (n == 1 && m == 1) {
        cin >> q;
        while (q--) {
            cin >> sx >> sy >> tx >> ty;
            cout << 0 << endl;
        }
        return;
    }

    if(n==1){
        vector < ll > dp(m+1, 0);
        for(i=2;i<=m;i++){
            dp[i]=dp[i-1]+pow(a[1][i-1]-a[1][i], k);
        }
        cin>>q;
        while(q--){
            cin >> sx >> sy >> tx >> ty;
            cout<<dp[ty] - dp[sy]<<endl;
        }
        return;
    }
    if(m==1){
        vector < ll > dp(n+1, 0);
        for(i=2;i<=n;i++){
            dp[i]=dp[i-1]+pow(a[i-1][1]-a[i][1], k);
        }
        cin>>q;
        while(q--){
            cin >> sx >> sy >> tx >> ty;
            cout<<dp[tx] - dp[sx]<<endl;
        }
        return;
    }

    if (n == 1) y = 0;
    else y = a[1][1] - a[2][1];
    if (m == 1) x = 0;
    else x = a[1][1] - a[1][2];
    x = abs(x);
    y = abs(y);
    bool inv = false;
    for (i = 1;i <= n;i++) {
        for (j = 1;j < m;j++) {
            t = abs(a[i][j + 1] - a[i][j]);
            if (t != x) {
                inv = true;
                break;
            }
        }
        if (inv) break;
    }
    for (j = 1;j <= m;j++) {
        for (i = 1;i < n;i++) {
            t = abs(a[i + 1][j] - a[i][j]);
            if (t != y) {
                inv = true;
                break;
            }
        }
        if (inv) break;
    }
    if (inv) {
        cin >> q;
        while (q--) {
            cin >> sx >> sy >> tx >> ty;
            cout << "INVALID\n";
        }
        return;
    }
    cin >> q;
    ll px = 1, py = 1;
    for (i = 0;i < k;i++) {
        px = px * x;
        py = py * y;
    }
    while (q--) {
        cin >> sx >> sy >> tx >> ty;
        cout << (a[sx][sy] - a[sx][ty]) / x * px + (a[sx][ty] - a[tx][ty]) / y * py << endl;
    }

}

int main() {
    // BOOST

    solve();

}