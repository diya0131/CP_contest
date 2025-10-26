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
    ll x, m, i, k = 1, s = 0, t;
    cin>>x>>m;
    while (k <= x) {
        k *= 2;
    }
    k = min(k, m);
    for (i = 1;i <= k;i++) {
        if(x==i) continue;
        t = i ^ x;
        if (i % t == 0 || x % t == 0) s++;
    
    }
    cout<<s<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}