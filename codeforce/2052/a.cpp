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
    ll n, i, j, k, s;
    cin>>n;
    vector< ll > a(n+1), b(n);
    vector< pair < ll, ll > > res;
    for(i=0;i<n;i++){
        cin>>b[i];
        a[i+1]=1;
    }
    for(i=n-1;i>=0;i--){
        for(j=b[i]-1;j>=1;j--){
            if(a[j]){
                res.pb({b[i], j});
            }
        }
        a[b[i]]=0;
        for(j=n-1;j>i;j--){
            res.pb({b[i], b[j]});
        }
    }
    cout<<res.size()<<endl;
    for(i=0;i<res.size();i++){
        cout<<res[i].ff _ res[i].ss<<endl;
    }
    
}

int main() {
    solve();
}