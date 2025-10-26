#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ss second
#define test if(te) cout

using namespace std;

const bool te = 0;



void solve() {
    ll n, i, k;
    cin >> n;
    vector < bool > vis(n, 0);
    cin >> k;
    vis[k - 1] = 1;
    bool res = true;
    for (i = 1;i < n;i++) {
        cin >> k;
        k--;
        bool can = false;
        if (k > 0 && vis[k - 1]) can = true;
        if (k < n - 1 && vis[k + 1]) can = true;
        vis[k]=1;
        if (!can) res = false;
    }
    if (res) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}