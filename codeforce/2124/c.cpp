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
    ll n, i, j, k, p=1, q, x, m;
    cin>>n;
    vector<ll>a(n);
    for(i=0;i<n;i++) cin>>a[i];
    for(i=n-2;i>=0;i--){
        if(a[i+1]%a[i]==0) continue;
        a[i]/=p;
        if(a[i+1]%a[i]==0) continue;
        m = gcd(a[i+1], a[i]);
        p*=a[i]/m;
    }
    cout<<p<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}