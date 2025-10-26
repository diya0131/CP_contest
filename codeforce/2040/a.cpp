#include<bits/stdc++.h>

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

const bool TEST = 0;

void solve() {
    int n, i, j, k, t;
    //wtf
    cin >> n >> k;
    vector < int > cnt(k, 0), a(n);
    for (i = 0;i < n;i++) {
        cin >> t;
        a[i] = t;
        cnt[t % k]++;
    }
    for (i = 0;i < k;i++) {
        if (cnt[i] == 1) {
            cout << "YES\n";
            for (j = 0;j < n;j++) {
                if (a[j] % k == i) {
                    cout << j + 1 << endl;
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}