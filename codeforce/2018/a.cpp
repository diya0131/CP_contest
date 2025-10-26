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
    int n, i, s, k, j=-1;
    cin>>n;
    int mx=0;
    for(i=0;i<n;i++){
        cin>>k;
        if(k==mx && i%2==0) {
            j=i;
        }
        if(k>mx){
            mx=k;
            j=i;
        }
    }
    if(n%2){
        if(j%2) cout<<mx+n/2<<endl;
        else cout<<mx+n/2+1<<endl;
    } else {
        cout<<mx+n/2<<endl;
    }
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}