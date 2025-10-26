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
    ll n, m, i, k, j, s,res=0;
    cin>>n>>m;
    vector dp(m+1, vector (m+1, 0LL));
    vector le(m+1, 0LL), ri(m+1, 0LL);
    j=0;
    for(i=0; i<n; i++){
        cin>>k;
        if(k==0){
            s=0;
            for(int l=0;l<=j;l++){
                s+=le[l];
                dp[j][l]+=s;
            }
            s=0;
            for(int l=j;l>=0;l--){
                s+=ri[l];
                dp[j][l]+=s;
            }
            j++;
            test<<j<<"hey\n";
            dp[j][0]=dp[j-1][0];
            test<<dp[j][0]<<" ";
            le[0]=0;
            ri[0]=0;
            for(int l=1;l<=j;l++){
                le[l]=0;
                ri[l]=0;
                dp[j][l]=max(dp[j-1][l], dp[j-1][l-1]);
                test<<dp[j][l]<<" ";
            }
            test<<endl;
            continue;
        } 
        if(k>0){
            if(k<=j) {
                test<<"li" _ k<<endl;
                le[k]++;
            }
        } else {
            if(j+k>=0) {
                test<<"ri" _ j+k<<endl; 
                ri[j+k]++;
            }
        }
    }
    s=0;
    for(int l=0;l<=j;l++){
        s+=le[l];
        dp[j][l]+=s;
    }
    s=0;
    for(int l=j;l>=0;l--){
        s+=ri[l];
        dp[j][l]+=s;
    }
    for(i=0;i<=m;i++){
        res=max(res, dp[m][i]);
    }
    cout<<res<<endl;
}

int main() {
    // BOOST
    solve();
    
}