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
    ll n, i, k, l = 1, r = 1000, m1, m2, m;
    while (l < r) {
        m = (r - l) / 3;
        m1 = l + m;
        m2 = l + 2 * m;
        cout << "?" _ m1 _ m2 << endl;
        cout.flush();
        cin >> k;
        if (k == (m1 + 1) * (m2 + 1)) r = m1;
        else {
            if (k == m1 * m2) l = m2 + 1;
            else {
                l = m1 + 1;
                r = m2;
            }
        }
    }
    cout << "!" _ l << endl;
    cout.flush();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}