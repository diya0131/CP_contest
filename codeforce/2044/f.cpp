#include<bits/stdc++.h>
#include<chrono>
#include<random>

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



void solve() {
    ll n, m, q, i, j, s = 0, sa = 0, sb = 0, k, t;
    cin >> n >> m >> q;
    ll a[n], b[m];
    for (i = 0;i < n;i++) {
        cin >> a[i];
        sa += a[i];
    }
    for (i = 0;i < m;i++) {
        cin >> b[i];
        sb += b[i];
    }
    unordered_set < ll > as, bs;
    for (i = 0;i < n;i++) {
        as.insert(sa - a[i]);
    }
    for (i = 0;i < m;i++) {
        bs.insert(sb - b[i]);
    }
    while (q--) {
        cin >> k;
        t = abs(k);
        bool can = false;
        for (i = 1;i * i <= t;i++) {
            if (t % i != 0) continue;
            if (as.count(i) > 0) {
                if (bs.count(k / i) > 0) {
                    can = 1;
                    cout << "Yes\n";
                    break;
                }
            }
            if (as.count(-i) > 0) {
                if (bs.count(-k / i) > 0) {
                    can = 1;
                    cout << "Yes\n";
                    break;;
                }
            }
            if (bs.count(i) > 0) {
                if (as.count(k / i) > 0) {
                    can = 1;
                    cout << "Yes\n";
                    break;;
                }
            }
            if (bs.count(-i) > 0) {
                if (as.count(-k / i) > 0) {
                    can = 1;
                    cout << "Yes\n";
                    break;;
                }
            }
        }
        if (!can) cout << "No\n";
    }

}

int main() {

    solve();

}