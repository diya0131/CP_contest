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
    ll k, i, x, v;
    cin>>k;
    x=sqrt(k);
    v=k-x*x+x;
    if(v>=0 && v<2*x+1){
        cout<<x*x+v<<endl;
    } else {
        x++;
        v=k-x*x+x;
        cout<<x*x+v<<endl;
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