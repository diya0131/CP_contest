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
    ll n,i, j, k, s=0, t, mn=LLONG_MAX, res, x=LLONG_MAX;
    cin>>n;
    vector<ll >a(n);
    bool fall=1;
    for(i=0;i<n;i++) cin>>a[i];
    res = a[0]+a[1];
    s = a[0];
    mn = a[0];
    for(i=1;i<n;i++){
        mn = min(mn, a[i]);
        x = min(x, max(0ll, a[i-1] - a[i]));
        if(i==n-1) {
            res = min(res, s + mn);
            continue;
        }
        if(fall){
            res = min(res, s+mn+min(x, a[i+1]));
        } else res = min(res, s+mn);
        
        
        s = s + mn;
        // cout<<i _ res _ x _ mn _ s<<endl;
        if(s>res) break;
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