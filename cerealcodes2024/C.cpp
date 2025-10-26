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
#define int ll

const int N = 3e5 + 7;
const int MOD = 1e9 + 7;
const int moveX[] = { -1, 0, 1, 0 };
const int moveY[] = { 0, 1, 0, -1 };
const int INFI = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);

void Solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum += p[i];
    }
    int rSum = 0, lSum = 0;
    int oscar, lora;
    int mx = 0;
    int idx = 0;
    int mx_l_sum, mx_r_sum;
    for (int i = 1; i < n; i++) {
        lSum = sum - rSum - p[0] - p[i];
        oscar = min(lSum, rSum) + p[i];
        lora = sum - oscar;
        if (oscar > mx) {
            mx = oscar;
            idx = i;
            mx_l_sum = lSum;
            mx_r_sum = rSum;
        }
        rSum += p[i];
    }
    lSum = mx_l_sum;
    rSum = mx_r_sum;
    int ans = sum - mx;
    int pt = idx;
    for (int i = 1; i < idx; i++) {
        rSum -= p[i];
        lSum += p[i - 1];
        lora = p[i] + max(lSum, rSum);
        oscar = sum - lora;
        while (pt < n && oscar < p[pt] + min(rSum + p[pt], lSum - p[pt + 1])) {
            rSum += p[pt];
            lSum -= p[pt + 1];
            pt++;
        }
        lora = p[i] + max(lSum, rSum);
        ans = max(ans, lora);
    }
    debug(ans);
    // cout << ans << endl;
}

signed main() {
    int test;
    cin >> test;
    while (test--) {
        Solve();
    }
}