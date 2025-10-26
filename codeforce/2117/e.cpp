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
    vector<ll>a(n), b(n);
    set < ll >st;
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++) cin>>b[i];
    if(a[n-1]==b[n-1]) {
        cout<<n<<endl;
        return;
    }
    for(i=n-2;i>=0;i--){
        if(a[i]==a[i+1] || b[i]==b[i+1]){
            cout<<i+1<<endl;
            return;
        }
        if(st.find(a[i])!=st.end() || st.find(b[i])!=st.end()){
            cout<<i+1<<endl;
            return;
        }
        if(a[i]==b[i]){
            cout<<i+1<<endl;
            return;
        }
        st.insert(a[i+1]);
        st.insert(b[i+1]);
    }
    cout<<0<<endl;

}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}