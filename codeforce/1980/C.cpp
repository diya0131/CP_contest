#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve() {
    ll n, m, i, j, k, s = 0, t;

    cin >> n;
    ll a[n], b[n];
    map < ll, int > mp;
    map < ll, bool > mb;
    for (i = 0;i < n;i++) cin >> a[i];
    for (i = 0;i < n;i++) cin >> b[i];
    for (i = 0;i < n;i++) {
        mb[b[i]] = true;
        if (a[i] != b[i]) {
            s++;
            if (mp.find(b[i]) == mp.end()) mp[b[i]] = 1;
            else mp[b[i]]++;
        }
    }

    cin >> m;
    for (i = 0;i < m;i++) {
        cin >> k;
        if (mp.find(k) != mp.end() && mp[k] > 0) {
            s--;
            mp[k]--;
        }
    }
    if (mb[k] && s == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}


