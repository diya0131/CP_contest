#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) (int)(x).size()
using namespace std;
const int N = 105;
mt19937 rnd(chrono::system_clock().now().time_since_epoch().count());
int _, n, x, y, ax, ay, xx, yy;
vector<int> ve;
signed main() {
    cin >> _;
    while (_--) {
        cin >> n;
        while (true) {
            x = rnd() % n + 1;
            y = rnd() % (n - 1) + 1;
            y += (y >= x);
            cout << "? " << n - 2;
            for (int i = 1;i <= n;i++)if (i != x && i != y)
                cout << ' ' << i;
            cout << endl;cin >> ax >> ay;
            if (ax == n / 2 && ay == n / 2 + 1)break;
        }
        ve.clear();
        for (int i = 1;i <= n;i++)if (i != x && i != y)ve.pb(i);
        for (int i = 0;i < n - 2;i += 2) {
            cout << "? 4 " << x << ' ' << y << ' ' << ve[i] << ' ' << ve[i + 1] << endl;
            cin >> ax >> ay;
            if (ax == n / 2 || ay == n / 2)xx = i;
            if (ax == n / 2 + 1 || ay == n / 2 + 1)yy = i;
        }
        if (xx == yy) {
            cout << "! " << ve[xx] << ' ' << ve[xx + 1] << endl;continue;
        }
        for (int i = 0, o = 1;i < 2 && o;i++)for (int j = 0;j < 2 && o;j++) {
            cout << "? 4 " << x << ' ' << y << ' ' << ve[xx + i] << ' ' << ve[yy + j] << endl;
            cin >> ax >> ay;
            if (ax == n / 2 && ay == n / 2 + 1)cout << "! " << ve[xx + i] << ' ' << ve[yy + j] << endl, o = 0;
        }
    }
    return 0;
}