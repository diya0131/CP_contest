
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
    ll n, m, i, j, x, s = 0, k;
    cin >> k;
    ll a[k];
    for (i = 0;i < k;i++) {
        cin >> a[i];
        for (j = 1;j < a[i];j++) cin >> x;
    }
    ll q = pow(2, 20);
    bool p = false;
    ll res = 0;

    for (i = 20;i >= 0;i--) {
        p = false;
        if (res & q) p = true;
        for (j = 0;j < k;j++) {
            test << "--" _ a[j] << endl;
            if (a[j] & q) {
                if (!p) {
                    res = res | q;
                    p = true;
                } else {
                    res = res | (q - 1);
                    cout << res << endl;
                    return;
                }
            }
        }
        q /= 2;
        test << "- " _ res << endl;
    }
    cout << res << endl;
    return;

}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}