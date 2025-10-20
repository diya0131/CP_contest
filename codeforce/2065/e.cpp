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
    int n, m, k, i, j;
    cin>>n>>m>>k;
    if(max(n, m) - min(n, m)>k || max(n, m)<k) {
        cout<<-1<<endl;
        return;
    }
    if(n>m){
        for(i=0;i<k;i++){
            cout<<'0';
        }
        
        for(i=0;i<n-k;i++){
            cout<<"10";
        }
        for(i=0;i<k-n+m;i++){
            cout<<'1';
        }
    } else {
        for(i=0;i<k;i++){
            cout<<'1';
        }
        for(i=0;i<m-k;i++){
            cout<<"01";
        }
        for(i=0;i<k-m+n;i++){
            cout<<'0';
        }

    }
    cout<<endl;
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}