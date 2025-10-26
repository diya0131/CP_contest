#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout<<
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = true;

void solve() {
    ll n, s, m, i, j, k, t, u, v;
    cin >> n >> s >> m;
    pair < ll, ll > pr[n];
    for (i = 0;i < n;i++) {
        cin >> u >> v;
        pr[i] = { u, v };
    }
    sort(pr, pr+n);
    k = 0;
    for (i = 0;i < n;i++) {
        if (pr[i].ff - k >= s) {
            cout << "YES\n";
            return;
        }
        k = pr[i].ss;
    }
    if (m - k >= s)    cout << "YES\n";
    else cout << "NO\n";

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}