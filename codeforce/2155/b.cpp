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
    int n, i, j, k, t;
    cin>>n>>k;
    t = n*n - k;
    if(k==n*n-1) {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    vector<vector<char>>a(n, vector<char>(n, 'U'));
    if(t>0){
        a[n-1][n-1]='L';
        a[n-1][n-2]='R';
        t-=2;
    }
    
    for(i=n-3;i>=0;i--){
        if(t==0) break;
        t--;
        a[n-1][i]='R';
    }
    for(i=0;i<n;i++){
        for(j=n-2;j>=0;j--){
            if(t==0) break;
            t--;
            a[j][i]='D';
        }
        if(t==0) break;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j];
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