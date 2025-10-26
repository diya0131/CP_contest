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

void solve(int idx) {
    ll n, i, m, s, t, p = 0;
    cin >> n;
    vector<ll>a(n);
    for (i = 0;i < n;i++) cin >> a[i];
    ll res = 0;
    for (i = 0;i < n;i++) {
        res += (n - i) * (i + 1);
    }
    map < ll, ll > mp;
    mp[0] = 1;
    ll x = 0;
    for (i = 0;i < n;i++) {
        x = x ^ a[i];
        t = 0;

        if (mp.find(x) != mp.end()) {
            if (mp[x] % 2 == 0) res -= (mp[x] / 2) * (mp[x] + 1);
            else res -= ((mp[x] + 1) / 2) * mp[x];
            // cout<<i _ x _ mp[x]<<endl;
            // mp[x]+=mp[x];
        }
        p = t;
        mp[x] += 1;
    }
    cout << "Case #" << idx << ": " << res << endl;
}

int main() {
    // BOOST
    freopen("input/narrowing_down_input.txt", "r", stdin);
    freopen("output/c_out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0;i < t;i++) {
        solve(i + 1);
    }
}