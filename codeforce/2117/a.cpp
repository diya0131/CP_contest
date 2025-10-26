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
    int n, x, i, s, j;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    i=0;
    while(i<n && a[i]==0){
        i++;
    }
    j=0;
    while(i<n && j<x){
        i++;
        j++;
    }
    while(i<n && a[i]==0) i++;
    if(i<n) cout<<"NO\n";
    else cout<<"YES\n";
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}