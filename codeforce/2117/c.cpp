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
    ll n, i, s, t, k;
    cin>>n;
    vector<ll>a(n), b(n, LLONG_MAX);
    for(i=0;i<n;i++) cin>>a[i];
    map < ll, ll > mp;
    for(i=n-1;i>=0;i--){
        if(mp.find(a[i])!=mp.end()) b[i] = mp[a[i]];
        mp[a[i]]=i;
    }
    // for(i=0;i<n;i++){
    //     cout<<b[i]<<" ";
    // }
    // cout<<endl;
    s=1;
    t=b[0];
    i=1;
    while(i<n){
        // cout<<i _ s _ t<<endl;
        k=0;
        if(t>=n){
            // s++;
            break;
        }
        for(;i<=t;i++){
            k = max(k, b[i]);
        }
        s++;
        t=k;
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