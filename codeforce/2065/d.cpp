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
    ll n, m, i, j, k, s, l;
    cin>>n>>m;
    vector< vector < ll > > a(n, vector<ll > (m));
    vector< pair < ll, ll > > b(n);
    for(i=0;i<n;i++){
        s=0;
        for(j=0;j<m;j++){
            cin>>a[i][j];
            s+=a[i][j];
        }
        b[i]={s, i};
    }
    sort(ALL(b));
    s=0;
    l=n*m;
    for(i=n-1;i>=0;i--){
        for(j=0;j<m;j++){
            s+=a[b[i].ss][j]*l;
            l--;
        }
    }
    cout<<s<<endl;
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}