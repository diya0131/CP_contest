#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define _ <<" "<<
#define ff first
#define ss second

using namespace std;

void solve() {
    ll n, k, s, i, j, t, m, ts, q, g, res = 0;
    cin >> n >> k >> s;
    m = ceil(log2(k)) + 1;
    vector < ll > a(n), b(n+1);
    for (i = 0;i < n;i++) {
        cin >> a[i];
    }
    j = 0;
    ts = 0;
    for (i = 0;i < n;i++) {
        ts += a[i];
        while (ts > s) {
            b[j] = i - 1;
            ts -= a[j];
            j++;
        }
    }
    for (;j < n;j++) {
        b[j] = n - 1;
    }
    vector < vector < ll > > up(n+1, vector < ll >(m));
    b[n] = n-1;
    for (i = n ;i >= 0;i--) {
        up[i][0] = b[i] + 1;
        for (j = 1;j < m;j++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    for (i = 0;i < n;i++) {
        t = k;
        q = 0;
        j = i;
        while (t > 0) {
            if (t % 2) {
                j = up[j][q];
            }
            q++;
            t /= 2;
        }
        res = max(res, j - i);
    }
    cout << res << endl;
}


int main() {
    ll t;
    cin >> t;
    while (t--) solve();
}