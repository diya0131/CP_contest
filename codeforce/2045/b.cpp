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

void solve() {
    ll n, d, s, i, k, t, mx, x;
    cin >> n >> d >> s;
    mx = min(n, 2 * d) / s;
    if (mx % 2) {
        bool can = true;
        x = mx;
        for (i = 3;i * i <= mx;i += 2) {
            while (x % i == 0) {
                if (s * (x - x / i) > d) {
                    can = false;
                    break;
                }
                x /= i;
            }
            if (can == false || x == 1) break;
        }
        if (x > 1) {
            if (s * (x - 1) > d) can = false;
        }
        if (can) cout << max(s, mx * s) << endl;
        else cout << max(s, (mx - 1) * s) << endl;
    } else {
        cout << max(s, mx * s) << endl;
    }

}

int main() {
    // BOOST
    solve();
}