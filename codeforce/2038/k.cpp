#include<bits/stdc++.h>
#include<chrono>
#include <random>

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const bool TEST = 0;

void solve() {
    ll n, k, i, j, p, a, b, m = 6000, res = 2;
    cin >> n >> a >> b;
    for (i = 1;i < n;i++) {
        res += (gcd(i + 1, a) + gcd(i + 1, b));
    }
    if (n < m) m = n;
    ll lsz = n / 3 - 1, msz = 2 * n / 3 - n / 3, rsz = n - lsz - msz - 2;
    vector < pair < ll, ll > > rowl(lsz), rowr(rsz), coll(lsz), colr(rsz);
    vector < pair < ll, pair <ll, ll > > > rowm(msz), colm(msz);
    vector < pair < ll, ll > > rrow(m), rcol(m);
    for (i = 1;i < n / 3;i++) {
        j = i - 1;
        rowl[j] = { gcd(a, i + 1), i };
        coll[j] = { gcd(b, i + 1), i };
    }
    for (i = n / 3;i < 2 * n / 3;i++) {
        j = i - n / 3;
        rowm[j] = { gcd(a, i + 1), {abs(i - n/2), i}};
        colm[j] = { gcd(b, i + 1), {abs(i - n/2), i}};
    }
    for (i = 2 * n / 3;i < n - 1;i++) {
        j = i - 2 * n / 3;
        rowr[j] = { gcd(a, i + 1), -i };
        colr[j] = { gcd(b, i + 1), -i };
    }
    sort(ALL(rowl));
    sort(ALL(coll));
    sort(ALL(rowm));
    sort(ALL(colm));
    sort(ALL(rowr));
    sort(ALL(colr));
    rrow[0] = { 0, gcd(a, 1) };
    rcol[0] = { 0, gcd(b, 1) };
    for (i = 1;i < m / 3;i++) {
        rrow[i] = { rowl[i - 1].ss, rowl[i - 1].ff };
        rcol[i] = { coll[i - 1].ss, coll[i - 1].ff };
    }
    for (i = m/3;i < 2*m / 3;i++) {
        j=i-m/3;
        rrow[i] = { rowm[j].ss.ss, rowm[j].ff };
        rcol[i] = { colm[j].ss.ss, colm[j].ff };
    }
    for (i = 2*m / 3;i < m - 1;i++) {
        j = i - 2*m / 3;
        rrow[i] = { -rowr[j].ss, rowr[j].ff };
        rcol[i] = { -colr[j].ss, colr[j].ff };
    }
    rrow[m - 1] = { n - 1, gcd(a, n) };
    rcol[m - 1] = { n - 1, gcd(b, n) };
    sort(ALL(rrow));
    sort(ALL(rcol));
    vector dp(m, vector(m, 0LL));
    for (i = 0;i < m;i++) {
        dp[0][i] = rrow[0].ss * rcol[i].ff;
    }
    for (i = 0;i < m;i++) {
        dp[i][0] = rcol[0].ss * rrow[i].ff;
    }
    for (i = 1;i < m;i++) {
        for (j = 1;j < m;j++) {
            dp[i][j] = min((dp[i - 1][j] + rcol[j].ss * (rrow[i].ff - rrow[i - 1].ff)), (dp[i][j - 1] + rrow[i].ss * (rcol[j].ff - rcol[j - 1].ff)));
        }
    }
    res += dp[m - 1][m - 1];
    cout << res << endl;
}

int main() {
    BOOST
        solve();

}