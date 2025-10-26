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
const ll M = 998244353;

void solve() {
    ll s, t, k, n, i, j, p, res =0, q=3;
    cin>>n;
    s = 0;
    if(n<=3) {
        cout<<n-1<<endl;
        return;
    }
    for(i=4;i<=n;i++){
        res=(res+s);
        s=(s+(s+(i-1)*(i-2)/2 - 2 - (i-2))*q);
        q=(q+1);
    }
    cout<<res+(n*(n-1)/2-2)<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}