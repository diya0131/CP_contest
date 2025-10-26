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

vector<int> par;

int head(int x) {
    if (par[x] == x) {
        return x;
    }
    return par[x] = head(par[x]);
}

bool join(int x, int y) {
    x = head(x);
    y = head(y);
    if (x == y) {
        return false;
    }
    par[x] = y;
    return true;
}

void Solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &num : a) {
        cin >> num;
    }
    par = vector<int>(n);
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
    vector<PII> ans;
    for (int i = n - 1; i > 0; i--) {
        vector<PII> d(n);
        for (int j = 0; j < n; j++) {
            d[j] = { a[j] % i, j };
        }
        sort(ALL(d));
        bool found = 0;
        for (int j = 1; j < n; j++) {
            auto x = d[j];
            auto y = d[j - 1];
            if (x.first == y.first && join(x.second, y.second)) {
                ans.push_back({ x.second + 1, y.second + 1 });
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < int(ans.size()); i++) {
        cout << ans[i].first _ ans[i].second << endl;
        // cout<< a[ans[i].ff-1] << " " << a[ans[i].ss-1]<<endl;
        cout<< (a[ans[i].ff-1] - a[ans[i].ss-1])%(n-i-1)<<endl;
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        Solve();
    }
}
