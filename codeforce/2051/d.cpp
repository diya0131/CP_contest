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
    ll n, x, y, i, j, k, s = 0, l, r, res=0;
    cin >> n >> x >> y;
    vector <ll> a(n);
    for (i = 0;i < n;i++) {
        cin >> a[i];
        s += a[i];
    }
    sort(ALL(a));
    for (i = 0;i < n;i++) {
        if(upper_bound(ALL(a), s - a[i] - x)==a.begin()) continue;
        r = prev(upper_bound(ALL(a), s - a[i] - x)) - a.begin();
        if(r==n) r--;
        l = lower_bound(ALL(a), s - a[i] - y) - a.begin();
        l = max(i+1, l);
        if(l<=r) res+=r-l+1;
    }
    cout<<res<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}