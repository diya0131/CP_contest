#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define int ll
#define sz(x) int(size(x))
#define _ << ' ' <<
#define ALL(x) x.begin(), x.end()
#define LLA(x) x.rbegin(), x.rend()

using PII = pair<int, int>;
using PLL = pair<ll, ll>;

#ifdef LOCAL
#include "/home/munhorgil/algo/debug.h"
#else
#define print(...) 42
#endif

const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

void Solve(int TEST) {
    int n;
    cin >> n;
    map<int, int> cnt;
    int x;
    vector<int> st;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cnt[x]++;
        if (cnt[x] == 2) {
            st.push_back(x);
            cnt[x] = 0;
        }
    }
    if (sz(st) < 4) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    sort(ALL(st));
    int a = st[0];
    int b = st[1];
    int c = st[sz(st) - 2];
    int d = st[sz(st) - 1];
    if((c-a)*(d-b)<(d-a)*(c-b)) swap(c, d);
    cout << a _ b _ a _ d _ c _ b  _ c _ d << endl;
}

signed main() {
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; i++) {
        Solve(i);
    }
}
