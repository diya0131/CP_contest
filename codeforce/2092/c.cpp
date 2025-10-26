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
    ll s1=0, s2=0, i, j, n, k, c1=0, c2=0, ma=0;
    bool sondgoi = false, tegsh=false;
    cin>>n;
    for(i=0;i<n;i++){
        
        cin>>k;
        ma=max(k, ma);
        if(k%2){
            sondgoi=1;
            c1++;
            s1+=k;
        } else {
            tegsh=1;
            c2++;
            s2+=k;
        }
    }
    if(sondgoi && tegsh){
        cout<<s1 + s2 - c1+1<<endl;
    } else{
        cout<<ma<<endl;
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