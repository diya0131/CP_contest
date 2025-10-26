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

const ll N = 1e6 + 1;
ll  val[N];

int main() {
    ll n, i, j, m, s, idx, t;
    cin >> n >> m;
    ll a[n], b[n], c[m];
    pair < ll, ll > p;
    for (i = 0;i < n;i++) cin >> a[i];
    for (i = 0;i < n;i++) cin >> b[i];
    for (i = 0;i < m;i++) cin >> c[i];

    p.ff = a[0];
    p.ss = 0;
    for (i = 0;i < N;i++) val[i] = N;
    for (i = 0;i < n;i++) {
        val[a[i]] = min(val[a[i]], a[i] - b[i]);
        if (p.ff - b[p.ss] > a[i] - b[i] || (p.ff - b[p.ss] == a[i] - b[i] && a[i] < p.ff)) {
            p.ff = a[i];
            p.ss = i;
        }
    }
    i = 0;
    while (i < N && val[i] == N) {
        val[i] = 0;
        i++;
    }
    t = val[i];
    for (;i < N;i++) {
        if (val[i] < t) t = val[i];
        if(i-t<0) cout<<"adiya"<<endl;
        else val[i] = 1 + val[i - t];
    }

    ll res = 0, tm = 0;
    t = p.ff - b[p.ss];
    for (i = 0;i < m;i++) {
        if (c[i] < N) res += val[c[i]];
        else {
            tm = (c[i] - p.ff) / t + 1;
            res += tm + val[c[i] - t * tm];
        }
    }
    cout << res * 2 << endl;
}