#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define test if(te) cout

using namespace std;

const bool te = 0;


void solve() {
    int n, k;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;i++) cin >> a[i];
    if (n == 2) {
        if (a[1] - a[0] == 1) cout << "NO\n";
        else  cout << "YES\n";
        return;
    }
    if (n <= 2) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {

        solve();
    }
}