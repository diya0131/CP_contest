#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define test if(te) cout

using namespace std;

const bool te = 0;


void solve() {
    ll n, q, i, j, k, s, x, y, x1, x2, y1, y2, res;
    cin >> n >> q;
    vector < string > a(n);
    map < string, ll > mp;
    map < char, ll > mp1;
    mp1['B'] = 0;
    mp1['G'] = 1;
    mp1['R'] = 2;
    mp1['Y'] = 3;
    mp["BG"] = 0;
    mp["BR"] = 1;
    mp["BY"] = 2;
    mp["GR"] = 3;
    mp["GY"] = 4;
    mp["RY"] = 5;

    for (i = 0;i < n;i++) {
        cin >> a[i];
    }
    vector < ll > last(6, -1);
    vector < vector < ll > > pref(n, vector < ll >(4, -1)), suff(n, vector < ll >(4, n + 1));
    for (i = 0;i < n;i++) {
        switch (a[i][0]) {
        case 'B':
            // pref[i][0] = max(pref[i][0], last[0]);
            pref[i][1] = max(pref[i][1], last[0]);
            pref[i][2] = max(pref[i][2], last[1]);
            pref[i][3] = max(pref[i][3], last[2]);
            break;
        case 'G':
            pref[i][0] = max(pref[i][0], last[0]);
            // pref[i][1] = max(pref[i][1], last[0]);
            pref[i][2] = max(pref[i][2], last[3]);
            pref[i][3] = max(pref[i][3], last[4]);
            break;
        case 'R':
            pref[i][0] = max(pref[i][0], last[1]);
            pref[i][1] = max(pref[i][1], last[3]);
            // pref[i][2] = max(pref[i][2], last[0]);
            pref[i][3] = max(pref[i][3], last[5]);
            break;
        case 'Y':
            pref[i][0] = max(pref[i][0], last[2]);
            pref[i][1] = max(pref[i][1], last[4]);
            pref[i][2] = max(pref[i][2], last[5]);
            // pref[i][3] = max(pref[i][3], last[0]);
            break;
        }
        switch (a[i][1]) {
        case 'B':
            // pref[i][0] = max(pref[i][0], last[0]);
            pref[i][1] = max(pref[i][1], last[0]);
            pref[i][2] = max(pref[i][2], last[1]);
            pref[i][3] = max(pref[i][3], last[2]);
            break;
        case 'G':
            pref[i][0] = max(pref[i][0], last[0]);
            // pref[i][1] = max(pref[i][1], last[0]);
            pref[i][2] = max(pref[i][2], last[3]);
            pref[i][3] = max(pref[i][3], last[4]);
            break;
        case 'R':
            pref[i][0] = max(pref[i][0], last[1]);
            pref[i][1] = max(pref[i][1], last[3]);
            // pref[i][2] = max(pref[i][2], last[0]);
            pref[i][3] = max(pref[i][3], last[5]);
            break;
        case 'Y':
            pref[i][0] = max(pref[i][0], last[2]);
            pref[i][1] = max(pref[i][1], last[4]);
            pref[i][2] = max(pref[i][2], last[5]);
            // pref[i][3] = max(pref[i][3], last[0]);
            break;
        }
       
        k = mp[a[i]];
        last[k] = i;

    }
    last.assign(6, n + 1);
    for (i = n - 1;i >= 0;i--) {
        switch (a[i][0]) {
        case 'B':
            // pref[i][0] = max(pref[i][0], last[0]);
            suff[i][1] = min(suff[i][1], last[0]);
            suff[i][2] = min(suff[i][2], last[1]);
            suff[i][3] = min(suff[i][3], last[2]);
            break;
        case 'G':
            suff[i][0] = min(suff[i][0], last[0]);
            // suff[i][1] = min(suff[i][1], last[0]);
            suff[i][2] = min(suff[i][2], last[3]);
            suff[i][3] = min(suff[i][3], last[4]);
            break;
        case 'R':
            suff[i][0] = min(suff[i][0], last[1]);
            suff[i][1] = min(suff[i][1], last[3]);
            // suff[i][2] = min(suff[i][2], last[0]);
            suff[i][3] = min(suff[i][3], last[5]);
            break;
        case 'Y':
            suff[i][0] = min(suff[i][0], last[2]);
            suff[i][1] = min(suff[i][1], last[4]);
            suff[i][2] = min(suff[i][2], last[5]);
            // suff[i][3] = min(suff[i][3], last[0]);
            break;
        }
        switch (a[i][1]) {
        case 'B':
            // suff[i][0] = min(suff[i][0], last[0]);
            suff[i][1] = min(suff[i][1], last[0]);
            suff[i][2] = min(suff[i][2], last[1]);
            suff[i][3] = min(suff[i][3], last[2]);
            break;
        case 'G':
            suff[i][0] = min(suff[i][0], last[0]);
            // suff[i][1] = min(suff[i][1], last[0]);
            suff[i][2] = min(suff[i][2], last[3]);
            suff[i][3] = min(suff[i][3], last[4]);
            break;
        case 'R':
            suff[i][0] = min(suff[i][0], last[1]);
            suff[i][1] = min(suff[i][1], last[3]);
            // suff[i][2] = min(suff[i][2], last[0]);
            suff[i][3] = min(suff[i][3], last[5]);
            break;
        case 'Y':
            suff[i][0] = min(suff[i][0], last[2]);
            suff[i][1] = min(suff[i][1], last[4]);
            suff[i][2] = min(suff[i][2], last[5]);
            // suff[i][3] = min(suff[i][3], last[0]);
            break;
        }
        for (j = 0;j < 6;j++) test << last[j] << " ";
        test << endl;
        test << i << endl;
        test << suff[i][0] _ suff[i][1] _ suff[i][2] _ suff[i][3] << endl;
        k = mp[a[i]];
        last[k] = i;
    }
    for (i = 0;i < n;i++) {
        test << i << endl;
        test << pref[i][0] _ pref[i][1] _ pref[i][2] _ pref[i][3] << endl;
        test << suff[i][0] _ suff[i][1] _ suff[i][2] _ suff[i][3] << endl;
    }
    while (q--) {
        cin >> x >> y;
        x--; y--;
        x1 = mp1[a[x][0]];
        x2 = mp1[a[x][1]];
        y1 = mp1[a[y][0]];
        y2 = mp1[a[y][1]];
        if (x1 == y1 || x1 == y2 || x2 == y1 || x2 == y2) {
            test << x1 _ x2 _ y1 _ y2 << endl;
            cout << abs(x - y) << endl;
            continue;
        }
        res = 10 * n + 1;
        k = pref[x][y1];
        if (k != -1) {
            test << k _ abs(x - k) + abs(y - k) _ 1 << endl;
            res = min(res, abs(x - k) + abs(y - k));
        }
        k = suff[x][y1];
        if (k != n + 1) {
            test << k _ abs(x - k) + abs(y - k) _ 2 << endl;
            res = min(res, abs(x - k) + abs(y - k));
        }
        k = pref[x][y2];
        if (k != -1) {
            test << k _ abs(x - k) + abs(y - k) _ 3 << endl;
            res = min(res, abs(x - k) + abs(y - k));
        }
        k = suff[x][y2];
        if (k != n + 1) {
            test << k _ abs(x - k) + abs(y - k) _ 4 << endl;
            res = min(res, abs(x - k) + abs(y - k));
        }
        if (res == 10 * n + 1) cout << -1 << endl;
        else cout << res << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {

        solve();
    }
}