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
    int mx, mxi, i, n, s=0;
    cin>>n;
    vector< int > a(n);
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    mx = a[0];
    mxi=0;
    s=1;
    for(i=1;i<n;i++){
        if(mx<a[i]){
            mx = a[i];
            mxi = i;
            s=1;
        } else{
            if(mx==a[i]) s++;
        }
    }
    if(s==n) cout<<"NO\n";
    else{
        cout<<"YES\n";
        for(i=0;i<n;i++){
            if(i==mxi) cout<<1<<" ";
            else cout<<2<<" ";
        }
        cout<<endl;
    }
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}