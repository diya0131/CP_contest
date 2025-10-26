#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = 0;


void solve() {
    int n, m, k, i, j, l, q, p;
    cin >> l >> n >> m;
    vector < int > a(l);
    vector < ll > ar(7, 0), nxt(7, -1), in(7, 0), who(7, 0), pos(7, -1);
    for (i = 0;i < l; i++){
        cin>>k;
        a[i]=k-1;
    }
    for(i=0;i<l-1;i++){
        if(a[i]<7 && nxt[a[i]]==-1){
            if(a[i+1]<7) nxt[a[i]]=a[i+1];
            else ar[a[i]]=1;
            who[a[i]]=i%2;
            pos[a[i]]=i;
        }
    }
    if(a[l-1]<7 && nxt[a[l-1]]==-1) {
        nxt[a[l-1]]=a[l-1];
        who[a[l-1]]=(l-1)%2;
        pos[a[l-1]]=l-1;
    }
    vector < vector < int > > b(n, vector< int >(m));
    for (i = 0;i < n;i++) {
        for (j = 0;j < m;j++) {
            cin >> k;
            b[i][j]=k-1;
            if(k-1<7) in[k-1]=1;
        }
    }
    vector < vector < vector< bool > > > dp(n, vector< vector< bool> >(m, vector< bool >(7, 0)));
   
    k = 2;
    if(b[n-1][m-1]<7){
        p=b[n-1][m-1];
        dp[n-1][m-1][p]=1;
        ar[p]=1;
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<7;j++){
            if(dp[i+1][m-1][j]) dp[i][m-1][j]=1;
        }
        if(b[i][m-1]<7){
            dp[i][m-1][b[i][m-1]]=1;
            ar[b[i][m-1]]=1;
        }
    }
    for(i=0;i<m-1;i++){
        for(j=0;j<7;j++){
            if(dp[n-1][i+1][j]) dp[n-1][i][j]=1;
        }
        if(b[n-1][i]<7){
            dp[n-1][i][b[n-1][i]]=1;
            ar[b[n-1][i]]=1;
        }
    }
    while (k<=min(n, m)){
        for(i=n-k;i>=0;i--){
            for(j=0;j<7;j++){
                if(dp[i+1][m-k][j] || dp[i][m-k+1][j]) dp[i][m-k][j]=1;
            }
            if(b[i][m-k]<7){
                p=b[i][m-k];
                if(nxt[p]==-1 || dp[i+1][m-k+1][nxt[p]]==0) {
                    // cout<<p _ nxt[p] _ i _ m-k _ dp[i+1][m-k+1][nxt[p]]<<endl;
                    dp[i][m-k][p]=1;
                    ar[p]=1;
                }
            }
        }
        for(i=m-k-1;i>=0;i--){
            for(j=0;j<7;j++){
                if(dp[n-k+1][i][j] || dp[n-k][i+1][j]) dp[n-k][i][j]=1;
            }
            if(b[n-k][i]<7){
                p=b[n-k][i];
                if(nxt[p]==-1 || dp[n-k+1][i+1][nxt[p]]==0) {
                    // cout<<p _ nxt[p] _ n-k _ i _ dp[n-k+1][i+1][nxt[p]]<<endl;
                    dp[n-k][i][p]=1;
                    ar[p]=1;
                }
            }
        }
        k++;
    }
    ll mn=l, wh;
    for(i=0;i<7;i++){
        // cout<<" __ " _ i _ in[i] _ pos[i] _ ar[i] _ nxt[i]<<endl;
        if(in[i] && pos[i]!=-1 && pos[i]<mn && ar[i]==1){
            mn=pos[i];
            wh=who[i];
        }
    }
    if(mn==l) wh=1;
    if(wh%2){
        cout<<"N"<<endl;
    }
    else cout<<"T"<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}