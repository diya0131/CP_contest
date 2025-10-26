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
const ll M = 1e9+7;

ll get(vector < ll >&dp, ll k, ll n){
    ll i=k, q=1;
    while(k+q<=n && dp[k+q]==dp[k]) q*=2;
    q/=2;
    // cout<<i _ q<<endl;
    while(q>0){
        // cout<<i _ q<<endl;
        if(dp[i+q]==dp[k]) i+=q;
        q/=2;
    }
    // cout<<"get" _ k _ dp[k] _ dp[i] _ dp[i+1]<<endl;
    return i;
}

vector < ll > bit;

void add(ll k, ll v, ll n){
    while(k<=n+1){
        bit[k]=(bit[k]+v)%M;
        k+=(-k)&k;
    }
}
ll sum(ll k){
    ll res=0;
    while(k>0){
        res=(res+bit[k])%M;
        k-=(-k)&k;
    }
    return res;
}

void solve() {
    ll n, m, i, j, s, k, mx=0, c, l, r, t;
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
    vector dp(n+1, LLONG_MAX), val(n+1, 0LL);
    bit.assign(n+2, 0);
    dp[0]=0;
    val[0]=1;
    add(0+1, 1, n);
    for(i=0;i<m;i++){
        s=0;
        l=1;
        // cout<<"---------------------------------------\n";
        for(j=1;j<=n;j++){
            s+=a[j];
            while(s>b[i]){
                // cout<<s _ b[i] _ a[l] _ l _ j<<endl;
                s-=a[l];
                l++;
            }
            // cout<<l _ j _ dp[j] _ dp[l-1] _ m-i-1<<endl;
            if(l<=j) {
                if(dp[l-1]+m-i-1==dp[j]){
                    if(dp[j-1]==dp[l-1]) r=j-1;
                    else r=get(dp, l-1, n);

                    t=((sum(r+1)-sum(l-1))%M+M)%M;
                    add(j+1, t, n);
                    // cout<<j _ l-1 _ t _ r _ "add" _ val[j] _ dp[j]<<endl;
                    val[j]=(val[j]+t)%M;
                }
                if(dp[l-1]+m-i-1<dp[j]){
                    dp[j]=dp[l-1]+m-i-1;
                    if(dp[j-1]==dp[l-1]) r=j-1;
                    else r=get(dp, l-1, n);
                    
                    t=((sum(r+1)-sum(l-1))%M+M)%M;
                    add(j+1, t-val[j], n);
                    // cout<<j _ l-1 _ t _ r _ "set" _ val[j] _ dp[j] _ t<<endl;
                    val[j]=t%M;
                }
            }
            // cout<<j _ dp[j]<<endl;
        }
    }
    // for(i=1;i<=n;i++){
    //     cout<<i _ dp[i] _ val[i]<<endl;
    // }
    cout<<dp[n] _ val[n]<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}