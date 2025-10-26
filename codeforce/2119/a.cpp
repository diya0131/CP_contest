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
    ll a, b, x, y, k;
    cin >> a >> b >> x >> y;
    if (a > b) {
        if (a - 1 == b && a % 2) cout << y << endl;
        else cout << -1 << endl;
    } else {
        if (x <= y) {
            cout << (b - a) * x << endl;
        } else {
            if (a % 2) {
                k = (b - a) / 2;
                cout << y * k + x * (b - a - k) << endl;
            } else {
                k = (b - a + 1) / 2;
                cout << y * k + x * (b - a - k) << endl;
            }
        }
    }
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}