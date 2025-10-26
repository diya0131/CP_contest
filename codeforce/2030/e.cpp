#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define BOOST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define test if(TEST) cout

using namespace std;

const bool TEST = 0;
const ll M = 998244353, N = 2e5 + 5;

ll getInv(ll k) {
    ll p = M - 2, q = k, res = 1;
    while (p > 0) {
        if (p % 2) res = (res * q) % M;
        p /= 2;
        q = (q * q) % M;
    }
    return res;
}
ll pw[N];
ll inv[N];

void solve() {
    ll n, i, j, k, s, su, t, sz, res = 0, left, nsz;
    cin >> n;
    vector < ll > cnt(n + 1, 0);
    for (i = 0;i < n;i++) {
        cin >> k;
        cnt[k]++;
    }
    vector < ll > pref(n, 0), tmp(n, 0), tmpcnt(n, 0), c(n, 0), cpref(n, 0), prefcnt(n, 0), ccnt(n, 0);
    c[0] = 1;
    left = n-cnt[0];
    for (j = 1;j <= cnt[0];j++) {
        c[j] = ((c[j - 1] * (cnt[0] - j + 1)) % M * inv[j]) % M;
        cpref[j] = (cpref[j - 1] + (c[j] * j) % M) % M;
        ccnt[j] = (ccnt[j - 1] + (c[j]) % M) % M;
    }
    for (j = 1;j <= cnt[0];j++) {
        pref[j] = cpref[j];
        prefcnt[j] = ccnt[j];
    }
    sz=cnt[0];
    for (i = 1;i < n;i++) {
        left -= cnt[i];
        res = (res + (pref[sz] * pw[left]) % M) % M;
        if (cnt[i] == 0) break;
        nsz=min(sz, cnt[i]);
        for (j = 1;j <= nsz;j++) {
            c[j] = ((c[j - 1] * (cnt[i] - j + 1)) % M * inv[j]) % M;
            cpref[j] = (cpref[j - 1] + (c[j] * j) % M) % M;
            ccnt[j] = (ccnt[j - 1] + (c[j]) % M) % M;
        }
        for (j = 1;j <= nsz;j++) {
            tmp[j] = (((prefcnt[j] - prefcnt[j - 1]) * pref[i]) % M * (cpref[cnt[i]] - cpref[i - 1]) % M + (prefcnt[sz] - prefcnt[j]) * (pref[sz] - pref[j]) % M * c[j] % M * j % M) % M;
            tmpcnt[j] = ((prefcnt[j] - prefcnt[j - 1]) * (ccnt[cnt[i]] - ccnt[i - 1]) % M + (prefcnt[sz] - prefcnt[j]) * (c[j]) % M);
        }
        for (j = 1;j <= nsz;j++) {
            pref[j] = tmp[j];
            prefcnt[j] = tmpcnt[j];
        }
        sz=nsz;
    }
    cout<<(res%M+M)%M<<endl;
}

int main() {
    // BOOST
    ll q = 1;
    for (ll i = 0;i < N;i++) {
        pw[i] = q;
        q = (q * 2) % M;
        inv[i] = getInv(i);
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}