#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ALL(a) a.begin(), a.end()
#define ss second
#define _ <<" "<<

using namespace std;

const bool te = 0;

void solve() {
    ll n, i, j, k;
    string s;
    cin >> s;
    n = s.size();
    bool p;
    for (i = n / 2+1;i < n;i++) {
        p = true;
        for (j = 0;j < i;j++) {
            if (s[j] != s[n - i + j]) {
                p = 0;
                break;
            }
        }
        if (p) {
            cout << "YES\n";
            for (j = 0;j < i;j++) {
                cout << s[j];
            }
            cout << endl;
            return;
        }
    }
    cout << "NO\n";

    // 6 - 4
    // 5 - 3
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}