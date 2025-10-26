#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define debug if(de) cout
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool de = true;
const ll M = 1e9 + 7;
const ll inv2 = 500000004;

ll inv(ll k) {
    // debug<<k<<endl;
    ll p = M - 2;
    ll q = k, s = 1;
    while (p > 0) {
        if (p % 2) {
            s = (s * q) % M;
        }
        q = (q * q) % M;
        p /= 2;
    }
    return s;
}

ll cnt(ll n, ll k) {
    ll q = 1, s = 0;
    for (int i = 0;i <= k;i++) {
        s = (s + q) % M;
        q = (q * (n - i)) % M;
        q = (q * inv(i + 1)) % M;
    }
    cout << n _ k _ s << endl;
    return s;
}

void solve() {
    ll n, m = 1, i, q, j, k, t;
    cin >> n >> k;
    q = 1;
    while (n / q > 1) {
        m++;
        q *= 2;
    }
    ll s = 0;
    t =n;
    k++;
    while (t > 0 && m > k) {
        if (n & q) {
            s += cnt(m - 1, m - k - 1);
            t -= q;
            k--;
        }
        q /= 2;
        m--;
    }
    // debug<<n _ m _ k _ s<<endl;
    s++;
    debug<<s _ ((n * (n + 1) % M * inv2) % M) _ s * (n - s) % M _ s * (s + 1) % M * inv2 % M<<endl;
    n++;
    ll res = ((n * (n + 1) % M * inv2) % M) - s * (n - s) % M - s * (s + 1) % M * inv2 % M;
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}