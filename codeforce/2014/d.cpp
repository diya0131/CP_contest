#include<bits/stdc++.h>

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

const bool TEST = 0;

vector < ll > bt[2];

void add(ll n, ll k, ll v, ll p) {
    while (k <= n) {
        bt[p][k] += v;
        // k++;
        k += (k & (-k));
        // cout<<k<<endl;
    }
}

ll sum(ll k, ll p) {
    ll s = 0;
    while (k > 0) {
        s += bt[p][k];
        k -= (k & (-k));
    }
    return s;
}

void solve() {
    ll n, t, k, i, j, d, l, r;
    cin >> n >> d >> k;
    bt[0].clear();
    bt[0].assign(n + 1, 0);
    bt[1].clear();
    bt[1].assign(n + 1, 0);
    for (i = 0;i <k;i++) {
        cin >> l >> r;
        add(n, l, 1, 0);
        add(n, r, 1, 1);
    }
    ll mn = k+1, mni, mx = -1, mxi;
    for (i = 1;i + d - 1 <= n;i++) {
        t = k - (sum(n, 0) - sum(i + d - 1, 0)) - (sum(i - 1, 1) - sum(0, 1));
        if(mn>t){
            mn=t;
            mni=i;
        }
        if(mx<t){
            mx=t;
            mxi=i;
        }
    }
    cout << mxi _ mni << endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}