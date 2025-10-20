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
    ll n, m, i, j, k, s, x, y;
    cin>>n>>m;
    s=4*m;
    cin>>x>>y;
    for(i=1;i<n;i++){
        cin>>x>>y;
        s+=2*(x+y);
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