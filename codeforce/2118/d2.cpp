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

map < pair < ll, bool >, int > mp;

map < ll, ll > posmp;

bool go(vector<vector<ll>>& a, vector<vector<ll>>& b, vector< ll >& p, vector< ll >& d, ll pos, bool dir, ll k) {
    ll t, to;
    test << pos _ dir << endl;
    if (mp.find({ pos, dir }) != mp.end()) {
        // cout<<"----" _ mp[{pos, dir}]<<endl;
        if (mp[{pos, dir}] < 2) {
            return mp[{pos, dir}];
        } else {
            mp[{pos, dir}]++;
            if (mp[{pos, dir}] > 2) {
                // mp[{pos, dir}] = 0;
                return 0;
            }
        }
    } else {
        mp[{pos, dir}] = 2;
    }

    ll idx = posmp[pos];
    if (dir) {
        t = (pos + d[idx]) % k;
        test << "t" _ t << endl;
        // for(ll tmp:b[t]){
        //     cout<<tmp<<" ";
        // }
        // cout<<"haha " _ endl;
        if (upper_bound(ALL(b[t]), -pos) == b[t].end()) {
            // mp[{pos, dir}] = 1;
            return 1;
        } else {
            to = -*upper_bound(ALL(b[t]), -pos);
        }
    } else {
        t = (pos - d[idx] % k + k) % k;
        test << "t" _ t << endl;
        if (upper_bound(ALL(a[t]), pos) == a[t].end()) {
            // mp[{pos, dir}] = 1;
            return 1;
        } else {
            to = *upper_bound(ALL(a[t]), pos);
        }
    }
    test << to << endl;

    mp[{pos, dir}] = go(a, b, p, d, to, !dir, k);
    return mp[{pos, dir}];
}

void solve() {
    mp.clear();
    posmp.clear();
    ll n, k, s, t, to, i, j, q, pos;
    cin >> n >> k;
    vector< ll > p(n), d(n);
    vector< vector< ll > > a(k), b(k);
    for (i = 0;i < n;i++) cin >> p[i];
    for (i = 0;i < n;i++) {
        posmp[p[i]] = i;
        cin >> d[i];
        t = (p[i] % k - d[i] % k + k) % k;
        a[t].pb(p[i]);
        t = (p[i] % k + d[i] % k + k) % k;
        b[t].push_back(-p[i]);
    }
    for (i = 0;i < k;i++) {
        // cout<<i _ b[i].size()<<endl;
        for (int j = 0;j < b[i].size() / 2;j++) {
            swap(b[i][j], b[i][b[i].size() - 1 - j]);
        }
    }

    pair < ll, bool > pr;

    cin >> q;
    while (q--) {
        cin >> pos;
        pos = pos;
        t = pos % k;

        if (lower_bound(ALL(a[t]), pos) == a[t].end()) {
            cout << "YES\n";
        } else {
            to = *lower_bound(ALL(a[t]), pos);
            if (go(a, b, p, d, to, 1, k)) cout << "YES\n";
            else cout << "NO\n";
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