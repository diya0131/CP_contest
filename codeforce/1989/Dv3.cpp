#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ALL(a) a.begin(), a.end()
#define ff first
#define ss second
#define PII pair < int, int >
#define PLL pair < ll, ll >

using namespace std;

const ll N = 1e6 + 5;

int main() {
    ll n, i, j, m, s, idx, t, res = 0;
    cin >> n >> m;
    ll a[n], b[n], c[m];
    vector < ll > val(N);
    vector < ll > ch(N);
    for (i = 0;i < n;i++) cin >> a[i];
    for (i = 0;i < n;i++) cin >> b[i];
    for (i = 0;i < m;i++) cin >> c[i];

    for (i = 0;i < N;i++) {
        val[i] = 0;
        ch[i] = 0;
    }
    for (i = 0;i < n;i++) {
        if (a[i] < N) {
            if (ch[a[i]] == 0) ch[a[i]] = a[i] - b[i];
            if (ch[a[i]] > a[i] - b[i]) ch[a[i]] = a[i] - b[i];
        }
    }
    t = 0;
    for (i = 0;i < N;i++) {
        if (ch[i] > 0) {
            if (t == 0) {
                t = ch[i];
            } else t = min(ch[i], t);
        }

        if (t != 0) val[i] = 1 + val[i - t];
    }

    for (i = 0;i < m;i++) {
        if (c[i] < N) res += val[c[i]];
        else {
            s = (c[i] - N) / t + 1;
            res += s + val[c[i] - s * t];
        }
    }
    cout << res * 2 << endl;

}