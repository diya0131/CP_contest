#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define ss second
#define _ <<" "<<

using namespace std;

const bool te = 0;

const ll N = 1e9 + 7;

ll inv(ll k) {
    ll p = N - 2, res = 1;
    ll q = k;
    while (p > 0) {
        if (p % 2) {
            res = (res * q) % N;
        }
        q = (q * q) % N;
        p /= 2;
    }
    return res;
}

void solve() {
    ll n, i, j, k, s = 0, res = 0;
    cin >> n;
    ll a[n];
    for (i = 0;i < n;i++) {
        cin >> a[i];
        s = (s + a[i]) % N;
    }
    for (i = 0;i < n;i++) {
        s = ((s - a[i]) % N + N) % N;
        res = (res + s * a[i] % N) % N;
    }
    cout << res * inv(n) % N * inv(n - 1) % N * 2 % N<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}