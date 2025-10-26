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
    ll n, k, i, s=0, t, j;
    cin>>n>>k;
    string str;
    cin>>str;
    vector < ll > a(n-1);
    for(i=n-1;i>0;i--){
        if(str[i]=='1') s++;
        else s--;
        a[i-1]=s;
    }
    sort(ALL(a));
    s=0;
    t=0;
    for(i=n-2;i>=0;i--){
        s+=a[i];
        if(s>=k) {
            cout<<n - i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}