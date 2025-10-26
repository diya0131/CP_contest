#include<bits/stdc++.h>

#define ll long long 
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

pair < ll, ll > test(vector < ll >& a, vector < ll >& b, vector < ll >& c, ll k, ll n) {
    ll s = 0, i = 0, x, y;
    pair < ll, ll > res={-1, -1};
    while (s < k && i < n) {
        s += a[i];
        i++;
    }
    s = 0;
    x = i;
    while (s < k && i < n) {
        s += b[i];
        i++;
    }
    s = 0;
    y = i;
    while (s < k && i < n) {
        s += c[i];
        i++;
    }
    if (s >= k) {
        res.ff = x;
        res.ss = y;
    }
    return res;
}

void solve() {
    ll n, i, j, k, s = 0;
    cin >> n;
    pair< ll, ll> pr, res[3];
    vector < vector < ll > > a(3, vector< ll >(n));
    for (i = 0;i < n;i++) {
        cin >> a[0][i];
        s += a[0][i];
    }
    for (i = 0;i < n;i++) {
        cin >> a[1][i];
    }
    for (i = 0;i < n;i++) {
        cin >> a[2][i];
    }
    for (i = 0;i < 3;i++) {
        for (j = 0;j < 3;j++) {
            if (i != j) {
                k = 3 - i - j;
                pr = test(a[i], a[j], a[k], (s+2) / 3, n);
                if(pr.ff!=-1) {
                    res[i]={1, pr.ff};
                    res[j]={pr.ff+1, pr.ss};
                    res[k]={pr.ss+1, n};
                    cout<<res[0].ff _ res[0].ss _ res[1].ff _ res[1].ss _ res[2].ff _ res[2].ss<<endl;
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