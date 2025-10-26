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
    ll n, m, k, i, j, s, t;
    cin>>n>>m;
    vector < vector< ll >> a(n, vector< ll > (m));
    vector< ll > p(n, -1);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++){
        t = a[i][0]%n;
        if(p[t]!=-1){
            cout<<-1<<endl;
            return;
        }
        p[t]=i;
        for(j=0;j<m;j++){
            if(a[i][j]%n!=t){
                cout<<-1<<endl;
                return;
            }

        }
    }
    for(i=0;i<n;i++) cout<<p[i]+1<<" ";
    cout<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}