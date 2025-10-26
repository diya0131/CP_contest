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
    ll n, i, j, j1, k, t, res = 105, mn, s, l, ms;
    cin>>n;
    vector<ll>a(n);
    for(i=0;i<n;i++) cin>>a[i];
    if(n<=2){
        cout<<0<<endl;
        return;
    }
    t = 0;
    for(i=1;i<n;i++){
        t = max(t, min(a[i-1], a[i])+1);
    }
    res = 0;
    for(i=t;i<=100;i++){
        s=0;
        l=0;
        ms=0;
        j1=0;
        mn = 1000;
        for(j=0;j<n;j++){
            if(a[j]==i){
                ms++;
            }
            mn = min(mn, a[j]);
            if(a[j]>=i) s++;
            else s--;
            if(s<0){
                ms=0;
                s=0;
                mn = 1000;
                continue;
            } 
            if(ms>0 && i - mn > res) {
                res = i - mn;
                cout<<i _ mn _ j _ s _ ms<<endl;
            }
            
        }
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