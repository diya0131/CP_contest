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
    cin >> n;
    bool isS = true, isP=true;
    ll a[n];
    for (int i = 0;i < n;i++) cin>>a[i];
    for (int i = 0;i < n;i++) {
        cin >> m;
        if (m != a[i]) isS = 0;
        if(m!=a[n-1-i]) isP = 0;
    }
    if (!isS && !isP ) {
        cout << "Alice\n";
        return;
    }
    cout << "Bob\n";
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}