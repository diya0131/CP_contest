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
    ll n, i, j, s, k;
    cin>>n;
    string str;
    vector < ll > p(n);
    for(i=0; i<n; i++){
        cin>>str;
        s=0;
        for(j=0;j<i;j++){
            s+=(str[j]=='1');
        }
        for(j=i+1;j<n;j++){
            s+=(str[j]=='0');
        }
        p[s]=i+1;
    }
    for(i=0;i<n;i++) cout<<p[i]<<" ";
    cout<<endl;
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}