#include<bits/stdc++.h>
#include<random>
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
    int n, i, j, s=0, p=0, mn=INT_MAX;
    cin>>n;
    map < int , int > mp;
    for(int i=0;i<n;i++){
        cin>>p;
        mp[p]++;
    }
    vector<int> a;
    for(auto it=mp.begin();it!=mp.end();it++){
        a.pb(it->ss);
    }
    sort(ALL(a));
    for(int i=0;i<a.size();i++){
        if(s < (a.size() - i) * a[i]) s = (a.size() - i) * a[i];
    }
    // cout<<mn _ s<<endl;
    cout<<s<<endl;
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}