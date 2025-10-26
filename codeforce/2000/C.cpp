#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ss second
#define test if(te) cout

using namespace std;

const bool te = 0;



void solve() {
    ll n, t = 0, i, j, k, s, m;
    string str;
    cin >> n;
    map< ll, ll > mp;
    map< ll, char > le;
    vector < bool > vis(26, 0);
    vector < ll > a(n);
    for (i = 0;i < n;i++) {
        cin >> k;
        if (mp.find(k) == mp.end()) {
            mp[k] = t++;
        }
        a[i] = mp[k];
    }
    cin >> m;
    while (m--) {
        cin >> str;
        bool can = true;
        if (str.size() != n) {
            cout << "NO\n";
            continue;
        }
        vis.assign(26, 0);
        le.clear();
        t = 0;
        for (i = 0;i < n;i++) {
            if (vis[str[i] - 'a']) {
                if (le.find(a[i]) == le.end()) {
                    test<<"hello\n";
                    can = false;
                    break;
                } else {
                    if (le[a[i]] != str[i]) {
                        test<<"hello2\n";
                        can = false;
                        break;
                    }
                }
            } else {
                vis[str[i] - 'a'] = 1;
                if (le.find(a[i]) == le.end()) {
                    le[a[i]] = str[i];
                } else {
                    test<<"hello3\n";
                    can = false;
                    break;
                }
            }
        }
        if (can) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}