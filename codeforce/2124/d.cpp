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
    ll n, k, t, i, j;
    cin>>n>>k;
    vector<ll>a(n), c(n);
    vector<ll>b;
    for(i=0;i<n;i++){
        cin>>a[i];
        c[i]=a[i];
    }
    sort(ALL(c));
    t = c[k-1];
    for(i=0;i<n;i++){
        if(a[i]<=t){
            b.push_back(a[i]);
        }
    }
    n=b.size();
    
    ll l=0, r=n-1, s=0;
    while(l<=r){
        if(b[l]==b[r]) {
            l++;
            r--;
            continue;
        }
        if(b[l]!=t && b[r]!=t) {
            cout<<"NO\n";
            return;
        }
        if(n-s==k-1){
            cout<<"NO\n";
            return;
        }
        s++;
        if(b[l]==t) l++;
        else r--;
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