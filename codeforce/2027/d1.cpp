#include<bits/stdc++.h>

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

const bool TEST = 0;

void solve() {
    ll n, m, i, j, s, k, mx=0, c, l;
    cin>>n>>m;
    vector < ll > a(n+1), b(m);
    a[0]=0;
    for(i=1; i<=n; i++) {
        cin>>a[i];
        mx=max(mx, a[i]);
    }
    for(i=0; i<m; i++) cin>>b[i];
    if(mx>b[0]){
        cout<<-1<<endl;
        return;
    }
    vector dp(n+1, LLONG_MAX-10);
    dp[0]=0;
    for(i=0;i<m;i++){
        s=0;
        l=1;
        for(j=1;j<=n;j++){
            s+=a[j];
            while(s>b[i]){
                // cout<<s _ b[i] _ a[l] _ l _ j<<endl;
                s-=a[l];
                l++;
            }
            // cout<<l _ j _ dp[j] _ dp[l-1] _ m-i-1<<endl;
            if(l<=j) dp[j]=min(dp[j], dp[l-1]+m-i-1);
            // cout<<j _ dp[j]<<endl;
        }
    }
    cout<<dp[n]<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}