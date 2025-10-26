#include<bits/stdc++.h>

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

const bool TEST = 0;

void solve() {
    ll n, i, j, s, k;
    cin>>n;
    vector < pair < ll, ll > > a(n);
    for(i=0; i<n; i++){
        cin>>k;
        a[i]={k+i, i};
    }
    sort(ALL(a));
    set < ll > st;
    st.insert(n);
    for(i=0;i<n;i++){
        if(st.find(a[i].ff)!=st.end()){
            // cout<<a[i].ff _ a[i].ss _ a[i].ff+a[i].ss<<endl;
            st.insert(a[i].ff+a[i].ss);
        }
    }
    cout<<*prev(st.end())<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}