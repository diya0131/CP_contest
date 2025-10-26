#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = false;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    cout << min(n, k) * min(m, k) << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}