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
    int n, k;
    cin >> n >> k;
    vector<bool> incl(n + 5, false);
    vector<int> p(n + 5, -1);
    int u, v;
    while (k--) {
        cin >> u >> v;
        u--; v--;
        cout<<p.size()<<endl;
        cout<<u _ v<<endl;
        p[u] = v;
        p[v] = u;
        incl[u] = 1;
        incl[v] = 1;
        // cout<<
    }
    cout << "here\n";
    int l = 0, r = 1;
    int ans = 0;
    while (l != r) {
        cout<<l _ r<<endl;
        if (!incl[l]) {
            if ((abs(l - p[l]) - 1) % 2 == 1) {
                ans++;
            }
            r = p[l];
        } else {
            if (!incl[r]) {
                if ((abs(r - p[r]) - 1) % 2 == 1) {
                    ans++;
                }
                l = p[r];
            }
        }
        l = (l - 1 + n) % n;
        r = (r + 1) % n;
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