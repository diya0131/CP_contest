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
    ll n, i, j, k, s, b, c;
    cin>>n>>b>>c;
    if(b==0){
        if(c>=n) cout<<n<<endl;
        else {
            if(c==n-1 || c==n-2) cout<<n-1<<endl;
            else cout<<-1<<endl;
        }
        return;
    }
    if(c >=n) {
        cout<<n<<endl;
        return;
    }
    k = (n-1-c) / b+1;
    cout<<n - k<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}