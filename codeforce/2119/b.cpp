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
    double n, i, j, s=0, px, py, qx, qy, mx=0, k;
    cin>>n;
    cin>>px>>py>>qx>>qy;
    vector<double>a(n);
    for(i=0;i<n;i++) {
        cin>>a[i];
        s+=a[i];
        mx = max(mx, a[i]);
    }
    k = sqrt((px - qx)*(px - qx) + (py - qy)* (py - qy));
    
    if(mx - (s-mx) > k || s<k){
        cout<<"NO"<<endl;
        return;
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