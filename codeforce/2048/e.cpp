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

void solve() {
    ll n, m, i, j, k, s;
    cin>>n>>m;
    // cout<<n _ m<<endl;
    if(2*n<=m) {
        cout<<"NO\n";
        return;
    } else {
        vector< vector< int > > res(m, vector(2*n, 0));
        cout<<"YES\n";
        
        for(i=0;i<n;i++){
            k = 2*i;
            for(j=0;j<m;j++){
                res[j][k]=i;
                res[j][(k+1)%(2*n)]=i;
                k=(k+1)%(2*n);
            }
        }
        for(i=0;i<2*n;i++){
            for(j=0;j<m;j++){
                cout<<res[j][i]+1<<" ";
            }
            cout<<endl;
        }
        // cout<<"end\n";
    }
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}