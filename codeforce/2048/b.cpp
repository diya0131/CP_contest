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
    int n, i, j, k;
    cin>>n>>k;
    vector < int > a(n, -1);
    j=k-1;
    for(i=1;j<n;i++){
        a[j]=i;
        j+=k;
    }
    j=0;
    for(;i<=n;i++){
        while(j<n && a[j]!=-1) j++;
        if(j>=n) break;
        a[j]=i;
        j++;
    }
    for(i=0;i<n;i++) cout<<a[i]<<" ";
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