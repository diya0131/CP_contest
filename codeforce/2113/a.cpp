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
    ll k, a, b, x, y, t, s=0;
    cin>>k>>a>>b>>x>>y;
    if(a>b){
        swap(a, b);
        swap(x, y);
    }
    if(k>=a){
        t = (k-a)/x+1;
        s =max(s, t);
        if(k-t*x >= b){
            s = max(s, t + (k-t*x - b)/y +1);
        }
    }
    if(k>=b){
        t = (k-b)/y+1;
        s = max(s, t);
        if(k-t*y >= a){
            s = max(s, t + (k-t*y - a)/x +1);
        }
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