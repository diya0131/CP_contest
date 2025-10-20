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
    ll n, m, i, j, s=1, l;
    cin>>n>>m;
    vector<vector<ll>>a(n);
    vector<ll>cnt(m+1, 0);
    for(i=0;i<n;i++){
        cin>>l;
        a[i].resize(l);
        for(j=0;j<l;j++){
            cin>>a[i][j];
            cnt[a[i][j]]++;
        }
    }
    for(i=1;i<=m;i++){
        if(cnt[i]==0) {
            cout<<"NO\n";
            return;
        }
    }
    for(i=0;i<n;i++){
        bool can = true;
        for(j=0;j<a[i].size();j++){
            cnt[a[i][j]]--;
            if(cnt[a[i][j]]==0){
                can = false;
            }
        }
        for(j=0;j<a[i].size();j++){
            cnt[a[i][j]]++;
        }
        // cout<<i _ can<<endl;
        if(can) s++;
    }
    if(s>=3) cout<<"YES\n";
    else cout<<"NO\n";
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}