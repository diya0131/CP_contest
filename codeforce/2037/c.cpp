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
    ll n, i;
    cin>>n;
    if(n<=4){
        cout<<-1<<endl;
        return;
    }
    for(i=1;i<=n;i+=2){
        if(i!=5) cout<<i<<" ";
    }
    cout<<5 _ 4<<" ";
    for(i=2;i<=n;i+=2){
        if(i!=4) cout<<i<<" ";
    }
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