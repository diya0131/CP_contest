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
#define sz(a) int(a.size())

const int N = 3e5 + 7;
const int MOD = 1e9 + 7;
const int moveX[] = { -1, 0, 1, 0 };
const int moveY[] = { 0, 1, 0, -1 };
const int INFI = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);

int n, k;
vector<int> a;

void init() {
    cin >> n >> k;
    a = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

bool check(int m) {
    vector<int> dp(n, 0), b(n);
    for (int i = 0; i < n; i++) {
        b[i] = (a[i] >= m ? 1 : -1);
    }
    dp[0] = b[0];
    for (int i = 1; i < n; i++) {
        if (i % k == 0) {
            dp[i] = (a[i] >= m ? 1 : dp[i - k]);
            continue;
        }
        dp[i] = dp[i - 1] + b[i];
        if (i >= k) {
            dp[i] = max(dp[i], dp[i - k]);
        }
    }
    cout<<"check" _ m<<endl;
    for (int i = 0;i < n;i++) {
        cout << dp[i] << " \n"[i == n - 1];
    }
    return (dp[n - 1] > 0);
}

void Solve() {
    init();
    if (k == 1) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, a[i]);
        }
        cout << ans << endl;
        return;
    }
    int l = 1, r = 1e9, m, ans = 0;
    while (l <= r) {
        m = (l + r) / 2;
        if (check(m)) {
            ans = max(ans, m);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        Solve();
    }
}