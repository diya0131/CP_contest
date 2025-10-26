#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define ll long long
#define _ <<' '<<
#define mp make_pair
#define ALL(x) x.begin(), x.end()
#define LLA(x) x.rbegin(), x.rend()
#define PII pair < int , int >
#define PLL pair < ll , ll >
#define debug(n) cout << #n << " = " << n << endl;

const int N = 5e3 + 1;
const int MOD = 1e9 + 7;
const int moveX[] = { -1, 0, 1, 0 };
const int moveY[] = { 0, 1, 0, -1 };
const int INFI = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);

vector<vector<ll>> c(N);
void initComb() {
    c[0] = { 1, 0 };
    for (ll i = 1; i < N; i++) {
        c[i] = vector<ll>(i + 2, 0);
        c[i][0] = 1;
        for (ll j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
}
void Solve() {
    ll n;
    cin >> n;
    ll mex;
    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        mex = 2 * i + 1;
        if (n >= mex) {
            for (ll j = 0; j <= i; j++) {
                ans = (ans + ((c[n - i - 1 - j][i - j] * c[i + j][j]) % MOD * (i + 1 + j)) % MOD) % MOD;
            }
        } else {
            ans = (ans + (c[n][i] * mex) % MOD) % MOD;
        }
    }
    cout << ans << endl;
}

int main() {
    initComb();
    int test;
    cin >> test;
    while (test--) {
        Solve();
    }
}
