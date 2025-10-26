#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "/home/munhorgil/algo/debug.h"
#else
#define print(...) 42
#endif

#define int ll
#define _ << ' ' <<
#define ALL(x) x.begin(), x.end()
#define LLA(x) x.rbegin(), x.rend()
#define PII pair < int , int >
#define PLL pair < ll , ll >

const int N = 3e5 + 7;
const int MOD = 1e9 + 7;
const int INV = 285700002;
const int moveX[] = { -1, 0, 1, 0 };
const int moveY[] = { 0, 1, 0, -1 };
const double PI = acos(-1);

int Add(int x, int y) {
    return (x % MOD + y % MOD + MOD) % MOD;
}
int Sub(int x, int y) {
    return (x - y + MOD) % MOD;
}
int Mult(int x, int y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

void Solve(int TEST) {
    int n, x;
    cin >> n;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i] = Mult(p[i], INV);
    }
    vector<int> prob(1024, 0), tmp(1024, 0);
    prob[0] = 1;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < 1024; i++) {
            tmp[i] = Add(Mult(prob[i], ((1 - p[j]))%MOD), Mult(prob[i ^ a[j]], (p[j])%MOD));
        }
        for (int i = 0; i < 1024; i++) {
            prob[i] = tmp[i];
        }
    }
    for (int i = 0; i < 1024; i++) {
        if (prob[i]) {
            print(i, prob[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < 1024; i++) {
        // if (i<10) cout<<i _ prob[i]<<endl;
        ans = Add(ans, Mult(Mult(i, i), prob[i]));
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; i++) {
        Solve(i);
    }
}