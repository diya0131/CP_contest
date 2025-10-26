#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define ll long long
#define _ <<' '<<
#define mp make_pair
#define ALL(x) x.begin(), x.end()
#define LLA(x) x.rbegin(), x.rend()
#define PII pair < int , int >
#define PLL pair < ll , ll >
#define debug(n) cout << #n << " = " << n << endl;

const int N = 3e5 + 7;
const int MOD = 1e9 + 7;
const int moveX[] = { -1, 0, 1, 0 };
const int moveY[] = { 0, 1, 0, -1 };
const int INFI = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);

void Solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool exceeded = 0;
    ll ans = 0;
    ll pow = 0;
    ll num;
    for (int i = 1; i < n; i++) {
        if (exceeded) {
            if (a[i] == 1) {
                cout << "-1\n";
                return;
            }
            while (a[i] * a[i] < num) {
                a[i] *= 2;
                ans++;
            }
            ans += pow;
            pow++;
            num = a[i];
            continue;
        }
        if (a[i] < a[i - 1]) {
            if (a[i] == 1) {
                cout << "-1\n";
                return;
            }
            while (a[i] < a[i - 1]) {
                a[i] *= a[i];
                ans++;
            }
            if (a[i] > 1e6) {
                num = sqrt(a[i]);
                pow = 2;
                exceeded = 1;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        Solve();
    }
}
