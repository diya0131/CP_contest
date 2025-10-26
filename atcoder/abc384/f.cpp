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

int main() {
    BOOST
        ll n, i, j, k, s = 0, t, q, c, res = 0, mi = 0;
    cin >> n;
    ll a[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    res = (n + 1) * s;

    unordered_map < ll, pair < ll, ll > > mp[25];
    q = 2;
    for (i = 0;i < 25;i++) {
        for (j = 0;j < n;j++) {
            mp[i][a[j] % q].ff++;
            mp[i][a[j] % q].ss += a[j];
        }
        q *= 2;
    }

    for (i = 0;i < n;i++) {
        q = 2;
        for (j = 0;j < 25;j++) {
            mp[j][a[i] % q].ff--;
            mp[j][a[i] % q].ss -= a[i];
            q *= 2;
        }

        q = 2;
        for (j = 0;j < 25;j++) {
            // if(a[i]>=q) cout << i _ q _ a[i] * mp[j][(q - a[i] % q) % q].ff _ mp[j][(q - a[i] % q) % q].ss _ (a[i] * mp[j][(q - a[i] % q) % q].ff + mp[j][(q - a[i] % q) % q].ss) / q<< endl;
            res -= (a[i] * mp[j][(q - a[i] % q) % q].ff + mp[j][(q - a[i] % q) % q].ss) / q;
            q *= 2;
        }
        q = 2;
        // for (j = 0;j < 25;j++) {
        //     mp[j][a[i] % q].ff++;
        //     mp[j][a[i] % q].ss += a[i];
        //     q *= 2;
        // }
    }
    for (i = 0;i < n;i++) {
        k = a[i] * 2;
        while (k % 2 == 0) {
            k /= 2;
        }
        res -= 2 * a[i] - k;
    }
    cout << res << endl;

}