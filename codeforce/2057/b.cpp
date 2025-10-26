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
    ll n, k, s=0, i, t;
    cin>>n>>k;
    map< ll, ll > mp;
    map< ll, ll >::iterator it;
    for(i=0;i<n;i++){
        cin>>t;
        mp[t]++;
    }
    vector< ll > a;
    for(it=mp.begin();it!=mp.end();it++){
        a.push_back(it->ss);
        s++;
    }
    sort(ALL(a));
    i=0;
    while(i<a.size() && a[i]<=k){
        s--;
        k-=a[i];
        i++;
    }
    cout<<max(1LL, s)<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}