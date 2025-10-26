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

vector < vector < ll > > adj;

ll dfs(ll k){
    
    ll m = adj[k].size(), i;
    pair < ll, ll > pr;
    test<<"dfs" _ k _ m _ endl;
    if(m==0) return 1;
    vector < ll > a(m);
    i=0;
    for(ll to:adj[k]){
        a[i]=dfs(to);
        i++;
    }
    sort(ALL(a));
    multiset< pair < ll, ll > > st;
    if(m<3) return a[m-1]+1;
    st.insert({a[m-1]+1, 1});
    st.insert({a[m-2]+1, 1});
    test<<"start" _ a[m-1]+1 _ a[m-2]+1<<endl;
    for(i=m-3;i>=0;i--){
        pr = *st.begin();
        test<<"add" _ pr.ff+1 _ pr.ss+1 _ endl;
        test<<"add" _ a[i]+pr.ss _ pr.ss+1 _ endl;
        st.erase(st.begin());
        
        st.insert({pr.ff+1, pr.ss+1});
        st.insert({a[i]+pr.ss+1, pr.ss+1});
    }
    return prev(st.end())->ff;
}

void solve() {
    ll n, i, j, k, s;
    cin>>n;
    adj.clear();
    adj.resize(n);
    for(i=1;i<n;i++){
        cin>>k;
        k--;
        adj[k].pb(i);
    }
    // for(i=0;i<n;i++){
    //     cout<<i<<"--\n";
    //     for(int to:adj[i]) cout<<to <<" ";
    //     cout<<endl;
    // }
    cout<<dfs(0)-1<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}