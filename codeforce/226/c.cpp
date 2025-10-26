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
    ll n, i, res, k, f=0;
    string s;
    cin>>n>>s;
    k=0;
    for(i=n-1;i>=0;i--){
       
        if(k+1>i) break;
        if(s[i]=='1'){
            f+=i+1;
            k++;
        } else {
            if(k) k--;
        }
    }
    cout<<n*(n+1)/2-f<<endl;
    
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}