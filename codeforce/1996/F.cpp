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
const ll M = 1e9 + 7;

vector < ll > a, b;
ll res;

bool get(ll m, ll nd) {
    // cout<<"haha: " _ m <<endl;
    ll mcnt = 0, cnt = 0, sum = 0, i, n = a.size(), k;
    for (i = 0;i < n;i++) {
        if (a[i] < m) continue;
        k = (a[i] - m) / b[i] + 1;

        sum += k * a[i] - (k - 1) * k / 2 * b[i];
        if ((a[i] - m) % b[i] == 0) mcnt++;
        cnt += k;
    }
    
    if (cnt >= nd) {
        if (cnt - nd <= mcnt) {
            sum -= (cnt - nd) * m;
            res = max(res, sum);
        }
        return true;
    } else {
        res = max(res, sum);
        return false;
    }
}

void solve() {
    ll n, k, i, j, x = 0, y = 0, m;
    res=0;
    cin >> n >> k;
    a.clear();
    a.resize(n);
    b.clear();
    b.resize(n);
    for (i = 0;i < n;i++) {
        cin >> a[i];
    }
    for (i = 0;i < n;i++) {
        cin >> b[i];
    }
    ll l = 0, r = 1e9, mcnt, cnt;
    while (l+1< r) {
        m = (l + r) / 2;
        if (get(m, k)) {
            l = m;
        } else r = m;
    }
    get(l, k);
    get(r, k);
    cout<<res<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}