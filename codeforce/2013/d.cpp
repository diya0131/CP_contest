#include<bits/stdc++.h>
#include<chrono>
#include <random>

using ll = long long;


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
    ll n, h, r, mx, all=0, mn;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        
        cin >> a[i];
        all+=a[i];
    }
    // cout<<"here\n";
    stack<pair< ll, ll >> st;
    pair< ll, ll > pr;
    ll sum = 0, cnt = 0;
    for (ll i = n - 1;i >= 0;i--) {
        // cout<<i<<endl;
        sum = a[i];
        cnt = 1;
        h=a[i];
        // cout<<i _ "cur" _ a[i] _ sum _ h<<endl;
        while (st.size() > 0 && st.top().ff<h) {
            pr = st.top();
            st.pop();
            // cout<<"min" _ pr.ff _ pr.ss <<endl;
            sum += pr.ff*pr.ss;
            cnt += pr.ss;
            h = (sum -1)/cnt +1;
            // cout<<"her" _ sum _ cnt _ h<<endl;
        }
        if(sum%cnt){
            r = sum%cnt;
            h=(sum-1)/cnt+1;
            st.push(pair< ll, ll >({h, r}));
            st.push(pair< ll, ll >({h-1, cnt - r}));
            // cout<<"add" _ h _ r <<endl;
            // cout<<"add" _ h-1 _ cnt-r <<endl;
        } else {
            h=sum/cnt;
            st.push(pair< ll, ll >({h, cnt}));
            // cout<<"add" _ h _ cnt <<endl;
        }
    }
    mn = st.top().ff;
    mx = st.top().ff;
    while(!st.empty()){
        mx = st.top().ff;
        st.pop();
    }
    cout<<mx - mn<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}