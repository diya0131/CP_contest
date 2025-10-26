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
const ll M=998244353;

void solve() {
    ll n, i, k, j, s=0, su=0;
    cin>>n>>k;
    if(k==1) {
        cout<<1<<endl;
        return;
    }
    vector < ll > dp(n, 1);
    for(i=1;i<n;i++){
        if(i-k>=0){
            su=(su+s+dp[i-k]+1)%M;
            s=(s+dp[i-k]+1)%M;
            
        }
        if(i - k>=0){
            dp[i]=((3*dp[i-1]%M - su)%M+M)%M;
        } else {
            dp[i]=3*dp[i-1]%M;
        }
        // cout<<dp[i]<<" ";
    }
    cout<<(dp[n-1]%M+M)%M<<endl;
}

int main() {
    
    solve();
    
}