#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

void solve() {
    int n, m, i, j, k, s, x, y, l, ma;
    bool can;
    cin >> n >> m;
    int a[n][m];
    for (i = 0;i < n;i++) {
        for (j = 0;j < m;j++) {
            cin >> a[i][j];
        }
    }
    vector < pair < int, int > > sides;
    sides.pb({ 1, 0 });
    sides.pb({ -1, 0 });
    sides.pb({ 0, -1 });
    sides.pb({ 0, 1 });
    // cout<<"-------------"<<endl;
    for (i = 0;i < n;i++) {
        for (j = 0;j < m;j++) {
            // cout<<i _ "-------"<<j<<endl;
            can = true;
            ma = 0;
            for (l = 0;l < 4;l++) {
                x = i+sides[l].ff;
                y = j+sides[l].ss;
                // cout<<x _ y<<endl;
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    // cout<<a[x][y]<<endl;
                    if (a[x][y] >= a[i][j]) {
                        can = false;
                        break;
                    } else ma = max(ma, a[x][y]);
                }
            }
            if (can) {
                cout <<ma<<" ";
            } else cout <<a[i][j]<<" ";

        }
        cout<<endl;
    }
    // cout<<"-------------"<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}