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
    ll n, i, j, k, s, t, l, r, p, mx=LLONG_MIN, x, lx=LLONG_MIN, mxx=0;
    cin>>n;
    vector < ll > a(n);
    for(i=0;i<n;i++) cin>>a[i];
    s=0;
    x=0;
    for(i=0;i<n;i++){
        // cout<<i _ lx _ x _ mx<<endl;
        if(a[i]>mx) mx++;
        else if(a[i]<mx) mx--;
        if(a[i]>lx) mx=max(mx, lx+1);

        lx=max(lx, x);
        if(a[i]>x) x++;
        else if(a[i]<x) x--;
        if(i<n-1) mxx=max(mxx, x);
        
        // cout<<i _ lx _ x _ mx<<endl;
    }
    cout<<max(mxx, mx)<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}