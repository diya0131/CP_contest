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
    ll n, i, j;
    cin>>n;
    if(n==1) {
        cout<<"1 1\n";
        return;
    }
    if(n==2){
        cout<<"1 2 1 2\n";
        return;
    }
    if(n==3){
        cout<<"1 3 1 2 3 2\n";
        return;
    }
    if(n%2){
        cout<<n _ 1<<" ";
        for(i=n-3;i>=2;i-=2){
            cout<<i<<" ";
        }
        cout<<n-1<<" ";
        for(i=2;i<=n-3;i+=2){
            cout<<i<<" ";
        }
        cout<<n<<" ";
        for(i=n-2;i>=3;i-=2){
            cout<<i<<" ";
        }
        cout<<n-1 _ 1<<" ";
        for(i=3;i<=n-2;i+=2){
            cout<<i<<" ";
        }
        cout<<endl;
    } else {
        cout<<n _ 1<<" ";
        for(i=n-3;i>=3;i-=2){
            cout<<i<<" ";
        }
        cout<<1 _ n-1<<" ";
        for(i=3;i<=n-3;i+=2){
            cout<<i<<" ";
        }
        cout<<n<<" ";
        for(i=n-2;i>=2;i-=2){
            cout<<i<<" ";
        }
        cout<<n-1<<" ";
        for(i=2;i<=n-2;i+=2){
            cout<<i<<" ";
        }
        cout<<endl;
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