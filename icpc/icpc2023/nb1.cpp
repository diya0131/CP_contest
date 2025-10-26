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

const ll M = 1e9 + 7;

void add(ll& a, ll& b) {
    a = (a + b) % M;
}

void solve() {
    ll n, q, i, j, s, t, l, cnt = 0, ch, k, x, y, z, res;
    string str;
    cin >> n >> q;
    cin >> str;
    ll N = 150*150*150+1;;
    vector dp(n, vector(3, vector(N, 0LL)));
    if (str[0] == '?') {
        cnt++;
        dp[0][0][1][0] = 1;
        dp[0][1][0][1] = 1;
        dp[0][2][0][0] = 1;
    } else {
        dp[0][str[0] - 'a'][0][0] = 1;
    }
    for (i = 1;i < 2;i++) {
        if (str[i] == '?') cnt++;
        for (j = 0;j < N;j++) {
            for (l = 0;l < N;l++) {
                for (ch = 0;ch < 3;ch++) {
                    if (str[i] == '?') {
                        cout<<i _ j _ l _ cnt - j - l<<endl;
                        if( l>0 ) cout<<dp[i - 1][0][j][l - 1] _ "a"<<endl;
                        if( j>0 ) cout<<dp[i - 1][0][j-1][l] _ "b"<<endl;
                        if( cnt - j - l >0) cout<<dp[i - 1][0][j][l] _ "c"<<endl;

                        if (ch == 0) {
                            
                            if (l - 1 >= 0) add(dp[i][ch][j][l], dp[i - 1][1][j][l - 1]);
                            if (cnt - j - l >= 0) add(dp[i][ch][j][l], dp[i - 1][2][j][l]);
                        } else if (ch == 1) {
                            if (j - 1 >= 0) add(dp[i][ch][j][l], dp[i - 1][0][j - 1][l]);
                            if (cnt - j - l >= 0) add(dp[i][ch][j][l], dp[i - 1][2][j][l]);
                        } else {
                            if (l - 1 >= 0) add(dp[i][ch][j][l], dp[i - 1][1][j][l - 1]);
                            if (j - 1 >= 0) add(dp[i][ch][j][l], dp[i - 1][0][j - 1][l]);
                        }
                        cout<<dp[i][ch][j][l]<<endl;
                    } else {
                        if (ch == str[i] - 'a') {
                            for (ll i1 = 0;i1 < 3;i1++) {
                                if (ch != i1) dp[i][ch][j][l] += dp[i - 1][i1][j][l];
                            }
                        } else {
                            dp[i][ch][j][l] = 0;
                        }
                    }
                }
            }
        }
        
    }
    cout << "here\n";
    for (i = 0;i < n;i++) {
        for (j = 0;j < n;j++) {
            for (l = 0;l < n;l++) {
                cout << i _ j _ l _ dp[i][0][j][l] _ dp[i][1][j][l] _ dp[i][2][j][l] << endl;
            }
        }
    }
    vector pref(N, vector(N, 0LL));

    for (i = 0;i < N;i++) {
        s = 0;
        for (j = 0;j < N;j++) {
            k = (dp[n - 1][0][i][j] + dp[n - 1][1][i][j] + dp[n - 1][2][i][j]) % M;
            add(s, k);
            pref[i][j] = s;
        }
    }
    while (q--) {
        cin >> x >> y >> z;
        res = 0;
        for (i = 0;i <= x;i++) {
            k = cnt - i - z;
            if (k == 0) add(res, pref[i][y]);

            else {
                ll x = ((pref[i][y] - pref[i][k - 1]) % M + M) % M;
                add(res, x);
            }
        }
        cout << (res % M + M) % M << endl;
    }
}

int main() {
    // BOOST
    solve();

}