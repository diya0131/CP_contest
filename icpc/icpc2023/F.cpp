#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ss second
#define test if(te) cout

using namespace std;

const bool te = 0;

vector < ll > par, cnt;

ll getP(ll k){
    if(par[k]==k) return k;
    ll p=getP(par[k]);
    par[k]=p;
    return p;
}

void join(ll u, ll v){
    ll up=getP(u), vp=getP(v);
    if(up!=vp){
        par[up]=vp;
        cnt[vp]+=cnt[up];
    } 
}

bool can(vector < ll >& blk, ll n){
    ll m=blk.size(), i, j;
    vector < vector < bool > > dp(m+1, vector< bool > (n+1, 0));
    dp[0][0]=1;
    for(i=0;i<m;i++){
        for(j=0;j<=n;j++) dp[i+1][j]=dp[i][j];
        for(j=0;j<=n-blk[i];j++){
            if(dp[i][j]) {
                dp[i + 1][j + blk[i]] = 1;
            }
        }
    }
    return dp[m][n];
}

void solve(){
    ll n,i, j, k, s, t, x, y, l=0, r, m;
    cin>>n;
    par.resize(2*n);
    cnt.resize(2*n);
    vector < pair < ll, ll > > pts(2*n);
    vector < ll > blk;
    for(i=0;i<2*n;i++){
        cin>>x>>y;
        pts[i]={x,y};
    }
    vector< double > dis(n*(2*n-1));
    for(i=0;i<2*n;i++){
        for(j=i+1;j<2*n;j++){
            dis[l]=(pts[i].ff - pts[j].ff)*(pts[i].ff - pts[j].ff)+(pts[i].ss - pts[j].ss)*(pts[i].ss - pts[j].ss);
            l++;
        }
    }
    sort(dis.begin(), dis.end());
    r=n*(2*n-1)-1; // n(2*n - 1) - n*n (at least n*n dis >=k should exist)
    l=0;
    while(l<r){
        m=(l+r+1)/2;
        k=dis[m];
        for(i=0;i<2*n;i++){
            par[i]=i;
            cnt[i]=1;
        }
        for(i=0;i<2*n;i++){
            for(j=i+1;j<2*n;j++){
                if((pts[i].ff - pts[j].ff)*(pts[i].ff - pts[j].ff)+(pts[i].ss - pts[j].ss)*(pts[i].ss - pts[j].ss)<k) join(i, j);
            }
        }
        blk.clear();
        for(i=0;i<2*n;i++){
            if(par[i]==i){
                blk.pb(cnt[i]);
            }
        }
        bool cn = can(blk, n);
        if(cn) l=m;
        else r=m-1;
    }
    k=dis[l];
    printf("%.6lf\n", sqrt(k));
   
    for(i=0;i<2*n;i++){
        par[i]=i;
        cnt[i]=1;
    }
    for(i=0;i<2*n;i++){
        for(j=i+1;j<2*n;j++){
            if((pts[i].ff - pts[j].ff)*(pts[i].ff - pts[j].ff)+(pts[i].ss - pts[j].ss)*(pts[i].ss - pts[j].ss)<k) join(i, j);
        }
    }
    blk.clear();
    vector < ll > blki;
    for(i=0;i<2*n;i++){
        if(par[i]==i){
            blk.pb(cnt[i]);
            blki.pb(i);
        }
    }
    m=blk.size();
    vector < vector < ll > > dp(m+1, vector< ll > (n+1, 0));
    dp[0][0]=1;
    for(i=0;i<m;i++){
        for(j=0;j<=n;j++) dp[i+1][j]=dp[i][j];
        for(j=0;j<=n-blk[i];j++){
            if(dp[i][j] && dp[i][j+blk[i]]==0) {
                dp[i + 1][j + blk[i]] = i+1;
            }
        }
    }
    vector < bool > res(2*n, 0);
    k=n;
    while(k!=0){
        res[blki[dp[m][k]-1]]=1;
        k-=blk[dp[m][k]-1];
    }
    
    for(i=0;i<2*n;i++){
        if(res[getP(i)]) cout<<i+1<<endl;
    }
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
}