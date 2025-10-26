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

const int M = 1e9 + 7;

void add(int& a, int& b) {
    a = (a % M + b % M) % M;
}

void solve() {
    int n, q, i, j, s, t, l, cnt = 0, ch, k, x, y, z, res;
    string str;
    cin >> n >> q;
    cin >> str;
    int N = 170;
    vector dp(n, vector(3, vector(N, vector(N, 0))));
    vector < int > cnt1(3, 0);
    if (str[0] == '?') {
        cnt++;
        dp[0][0][1][0] = 1;
        dp[0][1][0][1] = 1;
        dp[0][2][0][0] = 1;
    } else {
        cnt1[str[0] - 'a']++;
        if (str[0] == 'a') dp[0][str[0] - 'a'][1][0] = 1;
        if (str[0] == 'b') dp[0][str[0] - 'a'][0][1] = 1;
        if (str[0] == 'c') dp[0][str[0] - 'a'][0][0] = 1;
    }
    for (i = 1;i < n;i++) {
        if (str[i] == '?') cnt++;
        else cnt1[str[i] - 'a']++;
        for (j = 0;j < N;j++) {
            for (l = 0;l < N;l++) {
                if (str[i] == '?') {
                    for (ch = 0;ch < 3;ch++) {

                        // cout<<i _ j _ l _ cnt - j - l _ char(ch+'a')<<endl;
                        // if( l>0 ) cout<<dp[i - 1][0][j][l - 1] _ "a"<<endl;
                        // if( j>0 ) cout<<dp[i - 1][0][j-1][l] _ "b"<<endl;
                        // if( cnt - j - l >0) cout<<dp[i - 1][0][j][l] _ "c"<<endl;

                        if (ch == 0) {
                            if (j == 0) continue;
                            add(dp[i][ch][j][l], dp[i - 1][1][j - 1][l]);
                            add(dp[i][ch][j][l], dp[i - 1][2][j - 1][l]);
                        } else if (ch == 1) {
                            if (l == 0) continue;
                            add(dp[i][ch][j][l], dp[i - 1][0][j][l - 1]);
                            add(dp[i][ch][j][l], dp[i - 1][2][j][l - 1]);
                        } else {
                            if (i + 1 - j - l == 0) continue;
                            add(dp[i][ch][j][l], dp[i - 1][0][j][l]);
                            add(dp[i][ch][j][l], dp[i - 1][1][j][l]);
                        }
                        // for (int p = 0; p < 3; p++) {
                        //     if (ch == p) continue;
                        //     add(dp[i][ch][j][l], dp[i - 1][p][j][l]);
                        //     // add(dp[i][ch][j][l], dp[i - 1][0][j][l]);
                        // }
                        // cout << "dp" _ dp[i][ch][j][l] << endl;
                    }
                } else {
                    ch = str[i] - 'a';
                    if (ch == 0) {
                        if (j == 0) continue;
                        add(dp[i][ch][j][l], dp[i - 1][1][j - 1][l]);
                        add(dp[i][ch][j][l], dp[i - 1][2][j - 1][l]);
                    } else if (ch == 1) {
                        if (l == 0) continue;
                        add(dp[i][ch][j][l], dp[i - 1][0][j][l - 1]);
                        add(dp[i][ch][j][l], dp[i - 1][2][j][l - 1]);
                    } else {
                        if (i + 1 - j - l == 0) continue;
                        add(dp[i][ch][j][l], dp[i - 1][0][j][l]);
                        add(dp[i][ch][j][l], dp[i - 1][1][j][l]);
                    }
                }
            }
        }

    }
    // cout << "here\n";
    // for (i = 0;i < n;i++) {
    //     for (j = 0;j < n;j++) {
    //         for (l = 0;l < n;l++) {
    //             cout << i _ j _ l _ dp[i][0][j][l] _ dp[i][1][j][l] _ dp[i][2][j][l] << endl;
    //         }
    //     }
    // }
    // cout << dp[5][2][1][2] _ dp[5][2][2][1] _ dp[5][2][2][2] << endl;
    vector pref(N, vector(N, 0));

    for (i = 0;i < N;i++) {
        s = 0;
        // cout<<i _ "------------\n";
        for (j = 0;j < N;j++) {
            k = (dp[n - 1][0][i][j] + dp[n - 1][1][i][j] + dp[n - 1][2][i][j]) % M;
            add(s, k);
            pref[i][j] = s;

        }
    }
    // for (i = 0;i < 5;i++) {
    //     cout << i _ " ----\n";
    //     for (j = 0;j < 5;j++) {
    //         cout << pref[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    while (q--) {
        cin >> x >> y >> z;
        res = 0;
        for (i = 0; i <= x; i++) {
            if (i + y + z < cnt || i > cnt) continue;
            k = max(0, cnt - i - z);
            // if (k > y || cnt - i - k > z || i + k + y < cnt) continue;
            // cout << "haha" _ i _ k _ y << endl;
            // cout<<"pref" _ 
            if (k + cnt1[1] - 1 < 0) add(res, pref[cnt1[0] + i][cnt1[1] + y]);
            else {
                int x = ((pref[cnt1[0] + i][cnt1[1] + y] - pref[cnt1[0] + i][k - 1 + cnt1[1]]) % M + M) % M;
                // cout << "x = " << x << endl;
                add(res, x);
            }
            // cout << res << endl;
        }
        cout << (res % M + M) % M << endl;
    }
}

int main() {
    // BOOST
    solve();

}