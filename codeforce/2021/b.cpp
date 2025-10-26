#include<bits/stdc++.h>

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

const bool TEST = 0;

void solve() {
    ll s = 0, n, i, j, k, x, p;
    cin >> n >> x;
    vector < ll > a(n + 1, 0);
    vector< ll > nxt(n + 1, 0);
    for (i = 0;i <= n;i++) nxt[i] = i + x;
    // cout<<n _ "dha;" _  x<<endl;
    for (i = 0; i < n; i++) {
        cin >> k;
        // cout<<"her" _ k<<endl;
        while (x > 0 && k <= n && a[k] == 1) {
            p = k;
            k = nxt[k];
            if(k<=n) nxt[p] = nxt[k];
        }
        if (k <= n) a[k] = 1;
    }
    for (i = 0;i <= n;i++) {
        if (a[i] == 0) {
            cout << i << endl;
            return;
        }

    }
    cout << n << endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}