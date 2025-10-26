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
    ll k, l1, r1, l2, r2, s = 0, l3, r3, q;
    cin>>k>>l1>>r1>>l2>>r2;
    q=1;
    while (q <= r2) {
        l3 = (l2 - 1) / q + 1;
        r3 = r2 / q;
        if(min(r3, r1)>=max(l3, l1)) {
            s+=min(r3, r1)-max(l3, l1)+1;
        }
        q*=k;
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