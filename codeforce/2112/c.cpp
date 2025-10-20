#include<bits/stdc++.h>
#include<random>
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
    ll n, i, j, mx, s=0, r, l;
    cin>>n;
    vector<int>a(n);
    for(i=0;i<n;i++) cin>>a[i];
    mx = a[n-1];
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            r = lower_bound(ALL(a), a[i]+a[j]) - a.begin();
            l = upper_bound(ALL(a), mx - a[i] - a[j]) - a.begin();
            l = max(j+1, l);
            // cout<<i _ j _ r _ l<<endl;
            s += max(0ll, r - l);
        }
    }
    cout<<s<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}