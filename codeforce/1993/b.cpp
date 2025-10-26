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
    ll n, i, j, res = 0, ev = 0, k, odd = -1;
    cin >> n;
    multiset < ll > even;
    for (i = 0;i < n;i++) {
        cin >> k;
        if (!(k % 2)) even.insert(k);
        else odd = max(odd, k);
    }
    test << odd << endl;
    res = even.size();
    if (odd == -1) {
        cout << 0 << endl;

    } else {
        for (auto it = even.begin();it != even.end();it++) {
            test << (*it) _ odd << endl;
            if ((*it) > odd) {
                cout<<res+1<<endl;
                return;
            } else {
                odd = (*it) + odd;
            }
        }
        test << "res: ";
        cout << res << endl;
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}