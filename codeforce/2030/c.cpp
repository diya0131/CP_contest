#include<bits/stdc++.h>

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

const bool TEST = 0;

void solve() {
    int n, i, j;
    string s;
    cin>>n>>s;
    if(s[0]=='1' or s[n-1]=='1'){
        cout<<"YES\n";
        return;
    }
    for(i=1;i<n;i++){
        if(s[i-1]=='1' && s[i]=='1'){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}