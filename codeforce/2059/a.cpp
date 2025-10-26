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
    ll n, i, k, s, a, b;
    set < ll > st;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
        st.insert(k);
    }
    a=st.size();
    st.clear();
    for(i=0;i<n;i++){
        cin>>k;
        st.insert(k);
    }
    b=st.size();
    if(a>=3 || b>=3) cout<<"YES\n";
    else{
        if(a==2 && b==2) cout<<"YES\n";
        else cout<<"NO\n";
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