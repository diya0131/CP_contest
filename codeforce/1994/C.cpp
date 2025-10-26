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
    ll n, m, i, j, x = 0, s = 0, res = 0, ma = 0, k, val, pr = 0;
    map < ll, bool > mp;
    cin >> n;
    for (i = 0;i < n;i++) {
        cin >> k;
        res += k;
        if (mp.find(k) == mp.end()) {
            mp[k] = true;
        } else {
            if (k > ma) {
                test << s _ i _ k _ ma << endl;
                if (i == s + 1) {
                    test << pr _ n-i _ "add"<<endl;
                    res+= pr * (n - i);
                    val = 1;
                }
                else {
                    pr = ma;
                    val = (i - s) * n;
                    val += (s - 1) * s / 2;
                    val -= (i - 1) * (i) / 2;
                }
                res += val * ma;
                test << val _ val * ma _ res << endl;
                s = i;
                ma = k;
            }
        }
    }
    test << s _ i _ "end" _ ma << endl;
    if (i == s + 1) val = 1;
    else {
        val = (i - s) * n;
        val += (s - 1) * s / 2;
        val -= (i - 1) * (i) / 2;
    }
    res += val * ma;
    test << val _ val * ma _ res << endl;
    test << "res: ";
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}