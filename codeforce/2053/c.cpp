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

ll k;

map < ll, pair < ll, ll > > mp;

pair < ll, ll> go(ll l, ll r) {
    pair < ll, ll > res = {0, 0}, pr;
    if (mp.find(r - l + 1) != mp.end()) {
        return { mp[r - l + 1].ff + mp[r - l + 1].ss * l, mp[r - l + 1].ss };
    }
    if (r - l + 1 < k) return {0, 0};
    ll m = (l + r) / 2;
    if ((r - l) % 2==0) {
        res.ff += m;
        res.ss++;
        pr = go(l, m - 1);
        res.ff+=pr.ff;
        res.ss+=pr.ss;
        pr = go(m + 1, r);
        res.ff+=pr.ff;
        res.ss+=pr.ss;
    } else {
        pr = go(l, m);
        res.ff+=pr.ff;
        res.ss+=pr.ss;
        pr = go(m + 1, r);
        res.ff+=pr.ff;
        res.ss+=pr.ss;
    }
    res.ff-=res.ss*l;
    mp[r - l + 1] = res;
    res.ff+=res.ss*l;
    return res;
}

void solve() {
    ll n, m = 0, l, r;
    mp.clear();
    cin >> n >> k;
    cout << go(1, n).ff << endl;


}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}