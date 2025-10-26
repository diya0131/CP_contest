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

bool check(vector< ll >& row, vector<ll >& col, ll n, ll m, vector< vector< ll > >& a, vector< vector< ll > >& b, ll q){
    ll i=n-1, j=m-1, s, tn=n, tm=m;;
    vector< pair < ll, ll > > rrow(n), ccol(m);
    for(i=0;i<n;i++) rrow[i]={row[i], i};
    for(i=0;i<m;i++) ccol[i]={col[i], i};
    vector< bool > ro(n, 0), co(m, 0);
    sort(ALL(rrow));
    sort(ALL(ccol));
    // cout<<"------------\n";
    // cout<<tn _ tm _ q<<endl;
    // for(i=0;i<n;i++){
    //     cout<<row[i] _ i<<endl;
    // }
    // for(i=0;i<m;i++){
    //     cout<<col[i] _ i<<endl;
    // }
    i=n-1;
    j=m-1;
    while(tn>0 && tm>0){
        // cout<<tn _ tm _ rrow[i].ff _ ccol[j].ff _ endl;
        if(i>=0 && rrow[i].ff==tm){
            // cout<<"ro" _ i <<endl;
            ro[rrow[i].ss]=1;
            tn--;
            i--;
            continue;
        }
        if(j>=0 && ccol[j].ff==tn){
            // cout<<"co" _ j <<endl;
            co[ccol[j].ss]=1;
            tm--;
            j--;
            continue;
        }
        break;
    }
    for(i=0;i<n;i++){
        if(ro[i]) continue;
        for(j=0;j<m;j++){
            if(co[j]) continue;
            if((a[i][j]/q)%2!=(b[i][j]/q)%2) {
                // cout<<i _ j _ q _ ro[i] _ co[j]<<endl;
                return false;
            }
        }
    }
    return true;
}

void solve() {
    ll n, m, i, j, k, s, t, l;
    cin>>n>>m;
    vector < vector < ll > > a(n, vector<ll>(m)), b(n, vector<ll>(m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++) cin>>a[i][j];
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++) cin>>b[i][j];
    }
    vector< vector< ll > > row(30, vector<ll> (n, 0)), col(30, vector<ll> (m, 0));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            t=b[i][j];
            for(l=0;l<30;l++){
                if(t%2) col[l][j]++;
                else row[l][i]++;
                t/=2;
            }
        }
    }
    ll q = 1;
    for(i=0;i<30;i++){
        if(!check(row[i], col[i], n, m, a, b, q)){
            cout<<"No\n";
            return;
        }
        q*=2;
    }
    cout<<"Yes\n";
}

int main() {
    // BOOST
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}