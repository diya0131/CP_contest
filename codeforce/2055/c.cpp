#include<bits/stdc++.h>
#include<random>
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

void solve() {
    ll n, m, r, c, k, i, j, t, mn=LLONG_MAX;
    cin>>n>>m;
    string s;
    cin>>s;
    vector < vector < ll > > a(n, vector <ll>(m, 0LL));
    for(int i=0; i<n;i++){
        for(j=0;j<m;j++) cin>>a[i][j];
    }
    ll x=0, y=0, sum;
    for(i=0;i<(n+m-2);i++){
        // cout<<x _ y _ s[i] _ (s[i]=='D')<<endl;
        if(s[i]=='D'){
            sum =0;
            for(j=0;j<m;j++) sum+=a[x][j];
            a[x][y] = 0 - sum;
            mn = min(mn, a[x][y]);
            x++;
        } else {
            sum =0;
            for(j=0;j<n;j++) sum+=a[j][y];
            a[x][y] = 0 - sum;
            mn = min(mn, a[x][y]);
            y++;
        }
    }
    // cout<<"---" _ x _ y<<endl;
    sum =0;
    for(i=0;i<n;i++) sum+=a[i][y];
    a[x][y] = 0 - sum;
    mn = min(mn, a[x][y]);
    // cout<<"ROW\n";
    // for(i=0;i<n;i++){
    //     sum=0;
    //     for(j=0;j<m;j++){
    //         sum+=a[i][j];
    //     }
    //     cout<<i _ sum <<endl;
    // }
    // cout<<"COL\n";
    // for(i=0;i<m;i++){
    //     sum=0;
    //     for(j=0;j<n;j++){
    //         sum+=a[j][i];
    //     }
    //     cout<<i _ sum <<endl;
    // }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}