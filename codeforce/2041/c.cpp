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
    ll n, i, j, l, k, s;
    cin>>n;
    vector a(n, vector(n, vector< ll >(n)));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(l=0;l<n;l++){
                cin>>a[i][j][l];
            }
        }
    }
    ll sz = n*n*n;
    for(i=0;i<sz;i++){
        
    }
}

int main() {
    
    solve();
    
}