#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = false;

const ll N = 2e5 + 5, M = 1e9 + 7;

ll inv[N];

void setInv(ll k) {
    ll q = k, t = M - 2, res = 1;
    while (t > 0) {
        if (t % 2) res = (res * q) % M;
        q = (q * q) % M;
        t /= 2;
    }
    inv[k] = res;
}

void solve() {
    ll n, i, k, j, t, a = 0, b = 0, s = 0, q;
    cin >> n >> k;
    k = (k - 1) / 2;
    ll c1 = 1, c2 = 1;
    for (i = 0;i < n;i++) {
        cin >> t;
        if (t) a++;
    }
    b = n - a;

    t = min(2 * k + 1, a);

    for (i = 1;i <= t;i++) {
        c1 = c1 * (a - t + i) % M * inv[i] % M;
    }

    q = 2 * k + 1 - t;

    for (i = 1;i <= q;i++) {
        c2 = c2 * (b - q + i) % M * inv[i] % M;
    }
    test << t _ q << endl;
    for (i = q;i <= min(k, b);i++) {
        test << c1 _ c2 _ s << endl;
        s = ((c1 * c2) % M + s) % M;
        c1 = (c1 * t % M * inv[a - t + 1] % M);
        t--;
        c2 = (c2 * (b - q) % M * inv[q + 1] % M);
        q++;
    }
    test << "res: ";
    cout << s << endl;
    return;
}

int main() {
    inv[1] = 1;
    for (ll i = 2;i < N;i++) setInv(i);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}