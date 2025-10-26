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
    ll n, m, i, j, k, s, w;
    cin >> n >> m >> k;
    vector < ll > cnt(k * k + 1, 0);
    for (i = 0;i < n;i++) {
        for (j = 0;j < m;j++) {
            test << i _ j << endl;
            test << (min(k, i + 1) - (k - min(k, n - i) + 1) + 1) _(min(k, j + 1) - (k - min(k, m - j) + 1) + 1) << endl;
            test << min(k, i + 1) _(k - min(k, n - i) + 1)  _ min(k, j + 1) _(k - min(k, m - j + 1)) << endl;
            test << (min(k, i + 1) - (k - min(k, n - i) + 1) + 1) * (min(k, j + 1) - (k - min(k, m - j) + 1) + 1) << endl;
            if ((min(k, i + 1) - (k - min(k, n - i) + 1) + 1) * (min(k, j + 1) - (k - min(k, m - j) + 1) + 1) > k * k) {
                cout << "here" _ i _ j << endl;
            } else
                cnt[(min(k, i + 1) - (k - min(k, n - i) + 1) + 1) * (min(k, j + 1) - (k - min(k, m - j) + 1) + 1)]++;
            // if (i >= k - 1 && j >= k - 1 && i <= n - k && j <= m - k) {
            //     cnt[k * k]++;
            //     continue;
            // }
            // if (i >= k - 1 && i <= n - k) {

            //     cnt[k * (min(n, j + 1)-min(, m - j))]++;
            //     continue;
            // }
            // if (j >= k - 1 && j <= m - k) {
            //     cnt[k * min(i + 1, n - i)]++;
            //     continue;
            // }
            // cnt[min(i + 1, n - i) * min(j + 1, m - j)]++;
        }
    }
    cin >> w;
    vector < ll > he(w);
    for (i = 0;i < w;i++) {
        cin >> he[i];
    }
    sort(ALL(he));
    ll res = 0;
    i = k * k;
    while (w > 0 && i >= 0) {
        test << i _ cnt[i] _ w _ res << endl;
        if (cnt[i] > 0) {
            test << "added" _ i _ he[w - 1] _ i * he[w - 1] << endl;
            res += i * he[w - 1];
            w--;
            cnt[i]--;
        } else {
            i--;
        }
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}