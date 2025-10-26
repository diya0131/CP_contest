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
#define int ll

const int N = 3e5 + 7;
const int MOD = 1e9 + 7;
const int moveX[] = { -1, 0, 1, 0 };
const int moveY[] = { 0, 1, 0, -1 };
const int INFI = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);

signed main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector cost(26, vector<int> (26, -1));
    for (int i = 0; i < 26; i++) {
        cost[i][i] = 0;
        cost[i][25 - i] = 1;
        cost[i][(i + 13) % 26] = 2;
        cost[i][25 - (i + 13) % 26] = 3;
        if (25 - i == (i + 13) % 26) {
            cost[i][25 - i] = 4;
            cost[i][25 - (i + 13) % 26] = 5;
        }
    }
    vector<int> a(n);
    int c;
    for (int i = 0; i < n; i++) {
        c = cost[s[i] - 'a'][t[i] - 'a'];
        if (c == -1) {
            cout << "-1\n";
            exit(0);
        }
        a[i] = c;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    bool ok = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 5) {
            ok = 1;
            break;
        }
    }
    if (!ok) {
        cout << "1\n";
        exit(0);
    }
    if (a[0] == 5) {
        for (int i = 0; a[i] == 5; i++) {
            a[i] = 0;
        }
    }
    if (a[n - 1] == 5) {
        for (int i = n - 1; a[i] == 5; i--) {
            a[i] = 0;
        }
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i] == 5) {
            int l = i - 1;
            while (a[i] == 5) {
                i++;
            }
            int r = i;
            if (a[l] && a[r]) {
                for (int j = l + 1; j < r; j++) {
                    a[j] = 3;
                }
            } else {
                for (int j = l + 1; j < r; j++) {
                    a[j] = 0;
                }
            }
        }
    }
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 4) {
            int j = i;
            for (; j < n && a[j] == 4; j++) {}
            if (i - 1 >= 0) {
                l = a[i - 1];
            } else {
                l = 0;
            }
            if (j < n) {
                r = a[j];
            } else {
                r = 0;
            }
            if (l) {
                for (int k = i; k < j; k++) {
                    a[k] = l;
                }
            } else if (r) {
                for (int k = i; k < j; k++) {
                    a[k] = r;
                }
            } else {
                ans++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            while (i < n && (a[i] & 1)) {
                i++;
            }
            ans++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] & 2) {
            while (i < n && (a[i] & 2)) {
                i++;
            }
            ans++;
        }
    }
    cout << ans << endl;
}