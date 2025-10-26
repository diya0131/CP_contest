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

const ll M = 998244353;

void add(ll& a, ll b){
    a=(a+b)%M;
}

void solve() {
    ll n, m, i, j, k, s, t, q;
    cin>>n>>m;
    vector dpat(m+1, vector (m+1, 0LL));
    vector dpar(m+1, vector (m+1, 0LL));
    dpat[0][0]=1;
    for(i=2;i<=m;i+=2){
        dpat[i][0]=1;
        for(j=1;j<=i/2;j++){
            add(dpat[i][j], dpat[i-2][j-1]);
            if(j-1<(i-2)/2) add(dpat[i][j], dpat[i-2][j-1]);
            if(j-2>=0) add(dpat[i][j], dpat[i-2][j-2]);
            add(dpat[i][j], dpat[i-2][j]);
            // cout << i _ j _ dpat[i][j] _  dpat[i-2][j] _ dpat[i-2][j-1]<<endl;
        }
    }
    // dpar[0][0]=1;
    // for(i=2;i<=m;i+=2){
    //     for(j=0;j<=m;j+=2){
    //         add(dpar[i][j], dpar[i-2][j]);
    //         add(dpar[i][j], dpar[i-2][j]);
    //         if(j+2<=m) add(dpar[i][j], dpar[i-2][j+2]);
    //         if(j-2>=0) add(dpar[i][j], dpar[i-2][j-2]);
    //         cout << i _ j _ dpar[i][j]<<endl;
    //     }
    // }
    
    vector dpa(m+1, 0LL);
    vector dp(n+1, vector (m+1, 0LL));
    s=0;
    for(i=0;i<=m;i+=2) {
        // cout<<i _ dpat[m][m-(m/2+i/2)]<<endl;
        add(s, dpat[m][m-(m/2+i/2)]);
        // cout<<"dpa" _ i _ dpat[m][m-(m/2+i/2)] _ s<<endl;
        // dpa[i]=s;
        dpa[i]=dpat[m][m-(m/2+i/2)];
        dp[1][i]=dpat[m][m - (m/2+i/2)];
        // cout<<"dp" _ i _ dp[1][i] _ m- (m/2+i/2)<<endl;
    }
    s=0;
    for(i=2;i<=n;i++){
        s=0;
        for(j=m;j>=0;j--){
            t=j;
            while(t<=m){
                add(dp[i][j], dp[i-1][t]*dpa[t-j]%M);
                t+=2;
            }
            // add(s, dp[i-1][j]);
            // dp[i][j]=(s+dpa[m-j])%M;
        }
    }
    
    cout<<dp[n][0]<<endl;
}

int main() {
    // BOOST
    
    solve();
    
}