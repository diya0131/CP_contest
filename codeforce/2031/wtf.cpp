#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353, I = 1e6;
int binpow(int a, ll b) {
    int s = 1;
    while (b) {
        if (b % 2) {
            s = 1LL * s * a % mod;
        }
        a = 1LL * a * a % mod;
        b /= 2;
    }
    return s;
}
int fac[I + 1], ifac[I + 1];
int C(int n, int k) {
    if (k > n || k < 0) {
        return 0;
    }
    return 1LL * fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}
void init() {
    fac[0] = 1;
    for (int i = 1; i <= I; i++) {
        fac[i] = 1LL * fac[i - 1] * i % mod;
    }
    ifac[I] = binpow(fac[I], mod - 2);
    for (int i = I; i; i--) {
        ifac[i - 1] = 1LL * ifac[i] * i % mod;
    }
}
void bodooroi() {
    int n, k;
    cin >> n >> k;
    if (k >= n) {
        int ans = 1;
        for (int i = 0; i < n - 1; i++) {
            ans = 1LL * ans * 3 % mod;
        }
        cout << ans;
        return;
    }
    vector<int> dp(n);
    dp[0] = 1;
    int sum = 1, ans = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 2*dp[i-1]%mod;
        if (i - k >= 0) {
            dp[i] = ((dp[i]-dp[i-k])%mod+mod)%mod;
        }
        (ans += 1LL * sum * 2 % mod * C(n - 1, i) % mod) %= mod;
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); init();
    bodooroi();
    return 6/22;
}