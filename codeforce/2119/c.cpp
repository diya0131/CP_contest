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
    ll n, l, r, k, q=1, t;
    cin>>n>>l>>r>>k;
    t = l;
    if(n%2){
        cout<<l<<endl;
        return;
    }
    while(l>=2){
        l/=2;
        r/=2;
        q*=2;
    }
    if(r==1 || n==2) {
        cout<<-1<<endl;
        return;
    }
    if(k>=n-1){
        cout<<q*2<<endl;
    } else cout<<t<<endl;

}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}