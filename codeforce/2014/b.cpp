#include<bits/stdc++.h>

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
    int n, k, p, cnt;
    cin >> n >> k;
    if (n <= k) {
        if ((n) % 2) {
            cnt = ((n + 1) / 2) ;
        } else {
            cnt = ((n) / 2) ;
        }
    } else {
        if ((n) % 2) {
            cnt = ((n + 1) / 2) ;
        } else {
            cnt = ((n) / 2) ;
        }
        if ((n - k) % 2) {
            cnt -= ((n - k + 1) / 2);
        } else {
            cnt -= ((n - k) / 2) ;
        }
    }
    if(cnt%2) cout<<"NO\n";
    else cout<<"YES\n";
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}