#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ALL(a) a.begin(), a.end()
#define ss second
#define _ <<" "<<

using namespace std;

const bool te = 0;


void solve() {
    ll n, i, j, u, v, a = 0, b = 0, c = 0, d = 0;
    cin >> n;
    vector < ll > adj(n, 0);
    for (i = 1;i < n;i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u]++;
        adj[v]++;
    }
    string s;
    cin >> s;

    // cout << s _ "hel\n";
    for (i = 1;i < n;i++) {
        if (s[i] == '?') d++;
        // cout<<i _ adj[i] _ s[i]<<endl;
        if (adj[i] == 1) {
            if (s[i] == '?') c++;
            else {
                if (s[i] == '1') a++;
                else b++;
            }
        }
    }
    d = d - c;
    // cout << a _ b _ c _ d _ s << endl;
    if (s[0] == '?') {
        if (a == b && d % 2 && c % 2) {
            cout << a + (c + 1) / 2 << endl;
            return;
        }
        if (a == b) {
            cout << a + (c) / 2 << endl;
        } else {
            cout << max(a, b) + (c) / 2 << endl;
        }
    } else {
        if (s[0] == '0') {
            swap(a, b);
        }
        cout << b + (c + 1) / 2 << endl;
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}