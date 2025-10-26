#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ss second
#define test if(te) cout

using namespace std;

const bool te = 0;

struct dt {
    ll val;
    ll cnt;
    ll time;
};

void solve() {
    ll n, x, y, i, j, k, s, t = 0, cnt, diff, res = 0;
    cin >> n;
    stack < pair < ll, ll > > a;
    pair < ll, ll > pr;
    for (i = 0;i < n;i++) {
        cin >> x >> y;
        t = 0;
        while (!a.empty()) {
            pr = a.top();
            test << pr.ff _ pr.ss << endl;
            a.pop();
            if (pr.ss == y) {
                if (pr.ff > t) {
                    x += pr.ff - t;
                    t += pr.ff - t;
                    test << "added" _ t _ x _ pr.ss << endl;
                    res = max(res, x);
                }
            } else {
                if (pr.ff > x) {
                    test << "done" _ t _ y << endl;
                    a.push(pr);
                    a.push({ x, y });
                    x = 0;
                    break;
                } else {
                    test << "sub" _ x _ pr.ff _ x - pr.ff << endl;
                    t = max(t, pr.ff);
                }
            }
        }
        if (x > 0) {
            test << "new" _ t _ y << endl;
            a.push({ x, y });
            res = x;
        }

        cout << res << " ";
        test << "res\n";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}