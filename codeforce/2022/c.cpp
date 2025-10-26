#include<bits/stdc++.h>
#include<chrono>
#include <random>

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const bool TEST = 0;

void solve() {
    ll n, i, j, k, s, t, pt;
    char ch;
    cin >> n;
    vector < vector < bool > > a(2, vector < bool >(n+1));
    for (i = 0;i < 2;i++) {
        for (j = 0;j < n;j++) {
            cin >> ch;
            a[i][j+1] = (ch == 'A');
        }
    }
    vector < vector < ll > > dp(n + 1, vector < ll >(2, 0));
    for (i = 0;i <= n;i++) {
        if (i % 3 == 1) continue;
        if (i % 3 == 0) {
            if (i + 2 <= n) {
                pt = ((a[0][i + 1] + a[0][i + 2] + a[1][i + 1]) > 1);
                dp[i + 2][0] = max(dp[i + 2][0], dp[i][0] + pt);
                pt = ((a[0][i + 1] + a[1][i + 2] + a[1][i + 1]) > 1);
                dp[i + 2][1] = max(dp[i + 2][1], dp[i][0] + pt);
            }
            if(i+3<=n){
                pt = ((a[0][i + 1] + a[0][i + 2] + a[0][i + 3]) > 1);
                pt += ((a[1][i + 1] + a[1][i + 2] + a[1][i + 3]) > 1);
                dp[i + 3][0] = max(dp[i + 3][0], dp[i][0] + pt);
            }
        } else {
            if(i+3<=n){
                pt = ((a[0][i + 1] + a[0][i + 2] + a[0][i + 3]) > 1);
                pt += ((a[1][i] + a[1][i + 1] + a[1][i + 2]) > 1);
                dp[i + 3][0] = max(dp[i + 3][0], dp[i][0] + pt);
                pt = ((a[1][i + 1] + a[1][i + 2] + a[1][i + 3]) > 1);
                pt += ((a[0][i] + a[0][i + 1] + a[0][i + 2]) > 1);
                dp[i + 3][1] = max(dp[i + 3][1], dp[i][1] + pt);
            }
            if(i+1<=n){
                pt = ((a[0][i] + a[0][i + 1] + a[1][i + 1]) > 1);
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + pt);
                pt = ((a[1][i] + a[1][i + 1] + a[0][i + 1]) > 1);
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + pt);
            }
        }
    }
    
    cout<<dp[n][0]<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}