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
    int n, i, j, i1, i2, s, idx=-1;
    cin>>n;
    vector<int>a(n);
    
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    if(n==1) {
        cout<<"NO\n";
        return;
    }
    for(i=1;i<n;i++){
        if(a[i]<a[i-1]){
            cout<<"YES\n";
            cout<<2<<endl;;
            cout<<a[i-1]<<" "<<a[i]<<endl;
            return;
        }
    }
    cout<<"NO\n";
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}