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
    ll n, i, j, k;
    cin>>n;
    set < ll > st, left;
    set < ll >::iterator it;
    for(i=0;i<n;i++) left.insert(i+1);
    for(i=0;i<n;i++){
        cin>>k;
        if(st.count(k)==0){
            cout<<k<<" ";
            left.erase(k);
            st.insert(k);
        } else {
            it=left.begin();
            cout<<*it<<" ";
            left.erase(it);
            st.insert(*it);
        }
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