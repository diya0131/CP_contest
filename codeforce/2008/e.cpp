#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define ss second
#define _ <<" "<<

using namespace std;

const bool te = 0;

void solve() {
    ll n, i, j, k, l, r, c = 0, mx, res, pr, ls;

    cin >> n;
    ll dp[n + 1][26][2];
    ll cnt[26][2];
    string s;
    cin >> s;
    for (i = 0;i <= n;i++) {
        for (j = 0;j < 26;j++) {
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
    }
    for (j = 0;j < 26;j++) {
        cnt[j][0] = 0;
        cnt[j][1] = 0;
    }
    for (i = 1;i <= n;i++) {
        cnt[s[i - 1] - 'a'][i % 2]++;
        for (j = 0;j < 26;j++) {
            dp[i][j][0] = cnt[j][0];
            dp[i][j][1] = cnt[j][1];
        }
    }
    if (n % 2) {
        res = n;
        for (i = 1;i <= n;i++) {
            for (j = 0;j < 26;j++) {
                cnt[j][0] = dp[i - 1][j][0] + dp[n][j][1] - dp[i][j][1];
                cnt[j][1] = dp[i - 1][j][1] + dp[n][j][0] - dp[i][j][0];
            }
            pr = n - 1;
            mx = 0;
            for (j = 0;j < 26;j++) {
                mx = max(mx, cnt[j][0]);
            }
            
            pr -= mx;
            mx = 0;
            for (j = 0;j < 26;j++) {
                mx = max(mx, cnt[j][1]);
            }
            pr -= mx;
            // cout<<i _ pr<<endl;
            res = min(res, pr);

        }
        cout << res+1 << endl;

    } else {
        res = n;
        mx = 0;
        for (i = 0;i < 26;i++) {
            // cout<<"cnt" _ i _ 0 _ cnt[i][0]<<endl;
            mx = max(mx, cnt[i][0]);
        }
        // cout<<mx<<" ";
        res -= mx;
        mx = 0;
        for (i = 0;i < 26;i++) {
            // cout<<"cnt" _ i _ 1 _ cnt[i][1]<<endl;
            mx = max(mx, cnt[i][1]);
        }
        // cout<<mx<<" "<<endl;
        res -= mx;
        cout << res << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}