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
    ll n, m, k, i, j, s=0, x, y, t=0;
    cin>>n>>m>>k;
    vector<ll>a(m, 0);
    while(k--){
        cin>>x>>y;
        a[y-1]++;
    }
    if(m==1){
        cout<<"Yuyu\n";
        return;
    }
    if(n==1){
        for(int i=m-1;i>0;i--){
            s = (s+(a[i]+t))%2;
            t = (t+(a[i]+t))%2;
        }
        if(s%2){
            cout<<"Mimo\n";
        } else{
            cout<<"Yuyu\n";
        }
        return;
    }
    for(int i=m-1;i>0;i--){
        if(a[i]==0) continue;
        if(a[i]%2) {
            cout<<"Mimo\n";
        } else{
            cout<<"Yuyu\n";
        }
        return;
    }
    cout<<"Yuyu\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}