#include<bits/stdc++.h>
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

const bool TEST = 0;

void solve() {
    ll n, q, i, j, l, r, s, x, k;
    cin >> n >> q;
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(1e5, 1e9);
    map < ll, ll > mp;
    vector< ll > a(n), pref(n+1);
    x=0;
    pref[0]=0;
    for(i=0;i<n;i++){
        cin>>k;
        if(mp.find(k)==mp.end()){
            mp[k]=dist(rng);
        }
        x=(x ^ mp[k]);
        pref[i+1]=x;
    }
    while(q--){
        cin>>l>>r;
        if((pref[r] ^ pref[l-1])==0) cout<<"YES\n";
        else cout<<"NO\n";
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