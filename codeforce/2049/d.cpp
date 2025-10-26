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

void solve() {
    ll n, m, k, i, j, l, t;
    cin >> n >> m >> k;
    vector a(n, vector(m, 0LL));
    vector dp(n + 1, vector(m, LLONG_MAX));
    vector mi(n + 1, vector(m, vector(m, LLONG_MAX)));
    for (i = 0;i < m;i++) {
        dp[0][i] = i*k;
    }
    for (i = 0;i < m;i++) {
        for (j = 0;j < m;j++) mi[0][i][j] = 0;
    }
    for (i = 0;i < n;i++) {
        for (j = 0;j < m;j++) 
        cin >> a[i][j];
    }
    for(i=0;i<m;i++){
        mi[1][0][i]=a[0][i]+i*k;
    }
    for (i = 1;i <= n;i++) {
        for (j = 0;j < m;j++) {
            for (l = 0;l < m;l++) {
                if(i>1){
                    mi[i][j][l] = min(mi[i][j][l], dp[i - 1][j] + a[i-1][(j + l) % m]+ k * l);
                    // cout<<"down" _ dp[i - 1][j] _ a[i-1][(j + l) % m] _ k*l<<endl;
                }
                if(j>0) {
                    mi[i][j][l] = min(mi[i][j][l], mi[i][j - 1][l] + a[i-1][(j + l) % m]);
                    // cout<<"right" _ mi[i][j - 1][l]  _ a[i-1][(j + l) % m] _ k*l<<endl;
                }
                // mi[i][j][l] += k * l;
                // cout<<i _ j _ l _ mi[i][j][l]<<endl;
                dp[i][j] = min(dp[i][j], mi[i][j][l]);
            }
        }
    }
    // for(i=1;i<=n;i++){
    //     for(j=0;j<m;j++){
    //         cout<<dp[i][j] <<" ";
    //     }
    //     cout<<endl;
    // }
    cout << dp[n][m - 1] << endl;

}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}