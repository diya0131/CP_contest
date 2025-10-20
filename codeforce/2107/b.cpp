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
    ll n, k, i, mx, mn, s, c=1;
    cin>>n>>k;
    vector< ll > a(n);
    cin>>a[0];
    mx = a[0];
    mn = mx;
    s = mn;
    for(i=1;i<n;i++){
        cin>>a[i];
        s+=a[i];
        if(mx==a[i]) c++;
        else {
            if(mx<a[i]) c=1;
        }
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if(mx -1 - mn > k || (mx-mn>k && c>1)) cout<<"Jerry\n";
    else{
        if(s%2){
            cout<<"Tom\n";
        } else{
            cout<<"Jerry\n";
        }
    }
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}