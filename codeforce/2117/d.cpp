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
    ll n, x, y, s, i, j;
    cin>>n;
    vector<ll>a(n+1);
    for(i=0;i<n;i++) cin>>a[i+1];
    if((a[n]*n - a[1]) % (n*n-1) != 0) {
        cout<<"NO\n";
        return;
    }
    x = (a[n]*n - a[1]) / (n*n-1);
    y = a[n] - x*n;
    if(x<0 || y<0){
        cout<<"NO\n";
        return;
    }
    // cout<<x _ y<<endl;
    for(i=1;i<=n;i++){
        // cout<<i _ a[i] _ x*i+y*n-y*i+y <<endl;
        if(x*i+y*n-y*i+y != a[i]) {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}