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

ll get(ll x){
    return x - x/2 - x/3 - x/5 - x/7 + x/6 + x/10 + x/14 + x/15 + x/21 + x/35 - x/30 - x/70 - x/42 - x/105 + x/210;
}

void solve() {
    ll l, r, s=0;
    cin>>l>>r;
    cout<<get(r) - get(l-1)<<endl;
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}