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
    ll n, m, i, j, k, s, mx, c = 0, res = LLONG_MAX, cost, mxa, pos;
    cin >> n;
    vector < ll > a(n), b(n);
    for (i = 0;i < n;i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(ALL(b));
    mx = -1;
    map< ll, ll > mp;
    for (i = 0;i <= n;i++) {
        if (mx == -1) {
            cost = (n - i) * (n - i);
        } else {
            cost = (n - i) * (n - i) + (mx + 1) * (mx + 1);
        }
        res = min(res, cost);
        if(i<n){
            pos = lower_bound(ALL(b), a[i]) - b.begin() + mp[a[i]];
            if (pos != i &&( pos > mx || mx==-1)) {
                mx = pos;
            }
            mp[a[i]]++;
        }
    }

    mx = -1;
    mp.clear();
    for (i = n - 1;i >= -1;i--) {
        if (mx == -1) {
            cost = (i + 1) * (i + 1);
        } else {
            cost = (i + 1) * (i + 1) + (n - mx) * (n - mx);
        }
        res = min(res, cost);
        if(i>=0){
            pos = prev(upper_bound(ALL(b), a[i])) - b.begin() - mp[a[i]];
            if (pos != i && (pos < mx || mx ==-1)) {
                mx = pos;
            }
            mp[a[i]]++;
        }
    }
    cout<<res<<endl;
}

int main() {
    // BOOST
    
        solve();
    
}