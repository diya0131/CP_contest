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
    int n, c, i, s=0, t=0, q=1;
    cin>>n>>c;
    vector<int>a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sort(ALL(a));
    for(i=n-1;i>=0;i--){
        if(q > c) break;
        if(a[i]*q > c) continue;
        s++;
        q*=2;
    }
    cout<<n - s<<endl;
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}