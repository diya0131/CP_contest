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
    ll n, k, i, s, t;
    cin>>n>>k;
    vector < ll > a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==k){
        for(i=1;i<n;i+=2){
            if(a[i]!=(i+1)/2){
                cout<<(i+1)/2<<endl;
                return;
            }
        }
        cout<<n/2+1<<endl;
        return;
    } 

    int c=0;
    for(i=1;i<n;i++){
        if(a[i]==1) c++;
        else break;
    }
    if(c<=n-k){
        cout<<1<<endl;
    } else{
        cout<<2<<endl;
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