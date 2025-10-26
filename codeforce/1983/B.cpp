#include<bits/stdc++.h>

#define ll long long 
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

void solve() {
    int n, m, i, j, k, t;
    cin >> n >> m;
    string s;
    int a[n][m], b[n][m];
    for (i = 0;i < n;i++) {
        cin >> s;
        for (j = 0;j < m;j++) {
            a[i][j] = s[j] - '0';
        }
    }
    for (i = 0;i < n;i++) {
        cin >> s;
        for (j = 0;j < m;j++) {
            b[i][j] = s[j] - '0';
        }
    }
    for (i = 0;i < n - 1;i++) {
        for (j = 0;j < m - 1;j++) {
            if (a[i][j] == b[i][j]) continue;
            if ((a[i][j] + 1) % 3 == b[i][j]) {
                a[i][j] = b[i][j];
                a[i + 1][j + 1] = (a[i + 1][j + 1] + 1) % 3;
                a[i][j + 1] = (a[i][j + 1] + 2) % 3;
                a[i + 1][j] = (a[i + 1][j] + 2) % 3;
            } else {
                a[i][j] = b[i][j];
                a[i + 1][j + 1] = (a[i + 1][j + 1] + 2) % 3;
                a[i][j + 1] = (a[i][j + 1] + 1) % 3;
                a[i + 1][j] = (a[i + 1][j] + 1) % 3;
            }
        }
    }
    // for (i = 0;i < n;i++) {

    //     for (j = 0;j < m;j++) {
    //         cout << a[i][j];
    //     }
    //     cout << endl;
    // }
    bool can = true;
    for (i = 0;i < n;i++) {
        if (a[i][m - 1] != b[i][m - 1]) {
            can = false;
            break;
        }
    }
    for (i = 0;i < m;i++) {
        if (a[n - 1][i] != b[n - 1][i]) {
            can = false;
            break;
        }
    }
    if (can) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}