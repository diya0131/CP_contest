#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define ss second
#define _ <<" "<<

using namespace std;

const bool te = 0;

void solve() {
    ll n, i, j, k, s = 0, res = 0, t, g = 0;
    cin >> n >> k;
    for (i = 0;i < n;i++) {
        cin >> t;
        g = gcd(g, t);
    }
    if(n==1){
        if(t<k) cout<<k<<endl;
        else cout<<k-1<<endl;
        return;
    }
    if (g == 1) {
        cout << n + k - 1 << endl;
        return;
    }
    ll p = k / (g - 1);
    if(k%(g-1)==0) p--;
    cout << k - 1 + min(p + 1, n) << endl;
}

int main() {

    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}