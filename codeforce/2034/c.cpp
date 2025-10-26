#include<bits/stdc++.h>
#include<chrono>
#include <random>

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const bool TEST = 0;

ll n, m, s, r;
map < char, ll > mp;

void go(ll x, ll y, vector < vector < char > >& a, char road, ll cnt) {
    if (a[x][y] == 'x') {
        mp[road] = 0;
        return;
    }
    if (a[x][y] == '?') {
        mp[road] = 1;
        s += cnt;
        return;
    }
    switch (a[x][y]) {
    case 'D':
        a[x][y] = road;
        go(x + 1, y, a, road, cnt + 1);
        return;
    case 'U':
        a[x][y] = road;
        go(x - 1, y, a, road, cnt + 1);
        return;
    case 'L':
        a[x][y] = road;
        go(x, y - 1, a, road, cnt + 1);
        return;
    case 'R':
        a[x][y] = road;
        go(x, y + 1, a, road, cnt + 1);
        return;
    }
    if (a[x][y] == road) {
        s += cnt;
        mp[road] = 1;
        return;
    }
    mp[road] = mp[a[x][y]];
    if (mp[a[x][y]] == 1) {
        s += cnt;
    }
}

void solve() {
    ll i, j, x, y;
    cin >> n >> m;
    char road;
    s = 0;
    vector a(n + 2, vector <char >(m + 2, 'x'));
    for (i = 1;i <= n;i++) {
        for (j = 1;j <= m;j++) {
            cin >> a[i][j];

        }
    }
    road = 'x';
    mp.clear();
    mp['x']=0;
    for (i = 1;i <= n;i++) {
        for (j = 1;j <= m;j++) {
            if (a[i][j] != '?' && mp.find(a[i][j])==mp.end()) {
                road++;
                go(i, j, a, road, 0);
            }
        }
    }
    for (i = 1;i <= n;i++) {
        for (j = 1;j <= m;j++) {
            if (a[i][j] == '?') {
                bool done = false;
                x = i - 1;
                y = j;
                if (!done && (a[x][y]=='?' || mp[a[x][y]] == 1)) {
                    s++;
                    done = 1;
                } 
                x = i + 1;
                y = j;
                if (!done && (a[x][y]=='?' || mp[a[x][y]] == 1)) {
                    s++;
                    done = 1;
                }
                x = i;
                y = j - 1;
                if (!done && (a[x][y]=='?' || mp[a[x][y]] == 1)) {
                    s++;
                    done = 1;
                }
                x = i;
                y = j + 1;
                if (!done && (a[x][y]=='?' || mp[a[x][y]] == 1)) {
                    s++;
                    done = 1;
                }
                
            }
        }
    }
    cout << s << endl;
    // for(i=0;i<n+2;i++){
    //     for(j=0;j<m+2;j++){
    //         if(a[i][j]=='x' || a[i][j]=='?') cout<<a[i][j];
    //         else cout<<mp[a[i][j]];
    //     }
    //     cout<<endl;
    // }
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}