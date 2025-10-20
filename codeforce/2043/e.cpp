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
    ll n, m, i, j, k, t, q, s, r, c;
    cin>>n>>m;
    vector < vector < ll > > a(n, vector<ll> (m)), b(n, vector<ll> (m));
    vector < vector < ll > > row(m+1), col(n+1);
    vector < bool > rb(n+1), cb(m+1);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++) cin>>b[i][j];
    }
    q=1;
    for(ll l=0;l<30;l++){
        bool can = true;
        for(i=0;i<=m;i++) {
            row[i].clear();
            cb[i]=1;
        }
        for(i=0;i<=n;i++) {
            col[i].clear();
            rb[i]=1;
        }
        for(i=0;i<n;i++){
            s=0;
            for(j=0;j<m;j++){
                if((b[i][j] & q) ==0) s++; 
            }
            row[s].pb(i);
        }
        for(i=0;i<m;i++){
            s=0;
            for(j=0;j<n;j++){
                if((b[j][i] & q) !=0) s++; 
            }
            col[s].pb(i);
        }
        if(row[m].size()>0) i=1;
        else i=0;
        r = n;
        c = m;
        while(true){
            if(i%2){
                if(c==0) break;
                if(row[c].size()==0) break;
                r-=row[c].size();
                for(ll ro: row[c]){
                    rb[ro]=0;
                }
            } else{
                if(r==0) break;
                if(col[r].size()==0) break;
                c-=col[r].size();
                for(ll co: col[r]){
                    cb[co]=0;
                }
            }
            i++;
        }
        for(i=0;i<n;i++){
            if(!rb[i]) continue;
            for(j=0;j<m;j++){
                if(!cb[j]) continue;
                if((a[i][j] & q) != (b[i][j] & q)) {
                    cout<<"No\n";
                    return;
                } 
            }
        }
        q*=2;
    }
    cout<<"Yes\n";
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}