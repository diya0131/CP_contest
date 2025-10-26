#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define test if(te) cout

using namespace std;

const bool te = 0;


void solve() {
    ll n, i, j, l, k, x, y, c;
    cin >> n >> k;
    vector < vector < ll > > cost(n);
    for (i = 0;i < n;i++) {
        cin >> x >> y;
        c = 0;
        cost[i].pb(0);
        while (x > 0 && y > 0) {
            if (x < y) {
                c += x;
                y--;
            } else {
                c += y;
                x--;
            }
            cost[i].pb(c);
        }
        cost[i].pb(c);
        cost[i][cost[i].size() - 2] = INT_MAX;
    }
    vector < vector < ll > > dp(n, vector < ll >(k + 1, INT_MAX));

    for (j = 0;j < cost[0].size();j++) {
        if (j > k) break;
        dp[0][j] = cost[0][j];
        test << 0 _ j _ dp[0][j] << endl;
    }

    for (i = 1;i < n;i++) {
        for (j = 0;j < cost[i].size();j++) {
            for (l = j;l <= k;l++) {
                dp[i][l] = min(min(dp[i][l], dp[i - 1][l]), dp[i - 1][l - j] + cost[i][j]);
                test << i _ l _ dp[i][l] << endl;
            }

        }
    }
    if (dp[n - 1][k] == INT_MAX) cout << -1 << endl;
    else cout << dp[n - 1][k] << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {

        solve();
    }
}