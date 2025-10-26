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
    ll n, x, y, i, j, s;
    cin>>n;
    vector<pair < ll, ll > > a(n), b(n), c(n), d(n);
    vector<ll>cnt(n, 0);
    for(i=0;i<n;i++){
        cin>>x>>y;
        // st.insert(i);
        a[i] = {x, y};
        b[i] = {x, i};
        c[i] = {y, i};
    }
    sort(ALL(b));
    sort(ALL(c));
    
    
    for(i=n/2;i<n;i++){
        cnt[b[i].ss]+=1;
        cnt[c[i].ss]+=2;
    }

    vector<ll> arr[4];
    for(i=0;i<n;i++){
        arr[cnt[i]].pb(i+1);
    }
    for(i=0;i<arr[0].size();i++){
        cout<<arr[0][i] _ arr[3][i]<<endl;
    }
    for(i=0;i<arr[1].size();i++){
        cout<<arr[1][i] _ arr[2][i]<<endl;
    }
    
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}