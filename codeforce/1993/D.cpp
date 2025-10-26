#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = true;

bool check(vector < bool >& arr, ll p, ll k, ll a) {
    ll i, j, s = 0, t, n = arr.size();
    vector < ll > dp(n);
    test << "check" _ p _ k _ a << endl;

    for (i = 0;i < n;i++) {
        test << arr[i] << " \n"[i == n - 1];
    }
    for (i = 0;i < k;i++) {
        if (arr[i]) s++;
        else s--;
        dp[i] = s;
    }
    dp[k-1]=0;
    if (dp[k - 1] < 0) dp[k - 1] = 0;
    for (;i < n;i++) {
        if(i%k==k-1 && i!=n-1){
            dp[i]=dp[i-k];
            continue;
        }
        if (arr[i]) t = dp[i - 1] + 1;
        else t = dp[i - 1] - 1;
        dp[i] = t;
        if (dp[i - k] > t) dp[i] = dp[i - k];
    }
    for (i = 0;i < n;i++) {
        test << dp[i] << " \n"[i == n - 1];
    }
    return dp[n - 1] > 0;
}

void solve() {
    ll n, i, j, k, t, p = 0, p1, ma = 0, t1, mi;
    cin >> n >> k;
    vector < ll > a(n), b(n);
    vector < bool > tmp;
    t1 = n - ((n - 1) / k) * k;
    for (i = 0;i < n;i++) {
        cin >> a[i];
        b[i]=a[i];
        ma = max(a[i], ma);
    }
    if (k == 1) {
        cout << ma << endl;
        return;
    }
    sort(ALL(b));
    if (k >= n) {
        cout << b[(n - 1) / 2] << endl;
        return;
    }
    ll l = 0, r = n-1, mid, cnt;
    while (l + 1 < r) {
        mi=(l+r)/2;
        mid = b[mi];
        tmp.resize(n);
      
        cnt = 0;
        bool tk = false;
        for (i = 0;i < n;i++) {
            if (!(t1 % 2) && a[i] == mid && !tk) {
                tk = true;
                tmp[i]=0;
            }
            else {
                tmp[i] = (a[i] >= mid);
                cnt += tmp[i];
            }
        }
        if (check(tmp, mid, k, cnt)) l = mi;
        else r = mi;
    }
    tmp.resize(n);
    cnt = 0;
    for (i = 0;i < n;i++) {
        tmp[i] = (a[i] >= b[r]);
        cnt += tmp[i];
    }
    if (check(tmp, b[r], k, cnt)) {
        cout << b[r] << endl;
    } else {
        cout << b[l] << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}