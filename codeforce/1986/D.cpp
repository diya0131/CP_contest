#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

void solve() {
    int n, i, j, s = 0, t = 100, x, y, x1, y1, k;
    cin >> n;
    char a[n];
    bool can = false, isel = false;
    for (i = 0;i < n;i++) {
        cin >> a[i];
        if (a[i] == '0') can = true;
        if (a[i] != '1') s += (a[i] - '0');
    }
    if (n == 2) {
        cout << (a[0] - '0') * 10 + a[1] - '0' << endl;
        return;
    }
    if (n == 3) {
        x = (a[0] - '0') * 10 + a[1] - '0';
        x1 = a[2] - '0';
        y = (a[1] - '0') * 10 + a[2] - '0';
        y1 = a[0] - '0';
        cout << min(min(x * x1, x + x1), min(y * y1, y + y1)) << endl;
        return;
    }
    if (can) {
        cout << 0 << endl;
        return;
    }
    int res=INT_MAX;
    for (i = 1;i < n;i++) {
        k = (a[i - 1] - '0') * 10 + (a[i] - '0');
        t = 0;
        if(a[i-1]!='1') t+=a[i-1]-'0';
        if(a[i]!='1') t+=a[i]-'0';
        res = min(res, (s-t)+k);
    }
    
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}