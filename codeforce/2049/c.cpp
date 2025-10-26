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
    ll n, x, y, i, j, k, t=0;
    cin>>n>>x>>y;
    vector < ll > res(n);
    x--; y--;
    res[x]=1;
    res[y]=0;
    k=(x+1)%n;
    t=0;
    while(k!=y){
        res[k]=t;
        t^=1;
        k=(k+1)%n;
    }
    k=((x-1)%n+n)%n;
    t=0;
    while(k!=y){
        res[k]=t;
        t^=1;
        k=((k-1)%n+n)%n;
    }
    if(res[((y-1)%n+n)%n]==0) res[((y-1)%n+n)%n]=2;
    if(res[((y+1)%n+n)%n]==0) res[((y+1)%n+n)%n]=2;
    for(i=0;i<n;i++) cout<<res[i]<<" ";
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