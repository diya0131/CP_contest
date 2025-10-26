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

map < pair < ll, ll >, bool > mp;

ll ask(ll x, ll y){
    ll k;
    if(mp.find({x, y})!=mp.end()) return mp[{x, y}];
    cout<<"?" _ x _ y <<endl;
    cout.flush();
    cin>>k;
    mp[{x, y}]=k;
    return k;
}

void solve() {
    ll n, i, j, k, s, l, r, m, t;
    cin >> n;
    vector < bool > a(n+1, 0);
    mp.clear();
    for (i = 2;i <= n;i++) {
        k = ask(i-1, i);
        if (k == 1) a[i] = a[i - 1];
        else a[i] = !a[i - 1];
    }
    l=1;
    r=n;
    while(l<r){
        m = (l+r+1)/2;
        k = ask(1, m);
        t= (a[1]==a[m]);
        if(k == t){
            l=m;
        } else {
            r=m-1;
        }
    }
    if(l==n){
        k = ask(2, 1);
        t= (a[1]==a[2]);
        if(k!=t){
            l=1;
        }
    }
    cout<<"!" _ l<<endl;
    cout.flush();
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}