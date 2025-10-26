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
    ll n, i, j, k, t, p = 0, p1;
    cin >> n >> k;
    ll mia = 0, mib = k - 1, maa = k, mab = 2 * k - 1;
    for (i = 0;i < n;i++) {
        cin >> t;
        p = max(p, t);
        t = (t % (2 * k));
        if (t >= k) {
            mib = max(mib, t);
            maa = min(maa, t - k - 1);
        } else {
            mia = max(mia, t);
            mab = min(mab, t + k - 1);
        }
    }
    test << mia _ maa _ mib _ mab _ p _ p1 << endl;
    p1 = p % (2 * k);
    p = (p / (2 * k)) * 2 * k;
    
    test << mia _ maa _ mib _ mab _ p _ p1 << endl;
    if (p1 < k) {
        if (mia <= maa && p1 <= maa) {
            cout << p + max(mia, p1) << endl;
            return;
        } else {
            if (mib <= mab) {
                cout << p + mib << endl;
                return;
            } else {
                if (mia <= maa) {
                    cout << p + 2 * k + mia << endl;
                    return;
                }
            }
        }
    } else {
       
        if (mib <= mab && p1 <= mab) {
            cout << p + max(mib, p1) << endl;
            return;
        } else {
            if (mia <= maa) {
                cout << p + 2 * k + mia << endl;
                return;
            } else {
                if (mib <= mab) {
                    cout << p + 2 * k + mib << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}