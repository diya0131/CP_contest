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
    ll n, k, h, t, s, i, j, c=0;
    cin>>n>>k;
    vector<ll>a(n);
    for(i=0;i<n;i++) cin>>a[i];
    t = 0;
    c = a[k-1];
    sort(ALL(a));

    for(i=0;i<n-1;i++){
        if(a[i]<c) continue;
        if(a[i+1] - a[i] > a[i] - t){
            cout<<"NO\n";
            return;
        }
        t+=(a[i+1] - a[i]);
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