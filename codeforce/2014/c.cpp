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
    ll n, k, i, j, s=0, t;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    if(n<=2){
        cout<<-1<<endl;
        return;
    }
    sort(a, a+n);
    //3 - 1  4 - 2  5 - 2 
    k=a[n/2];
    // 2*n*k<(s+x)
    cout<<max(0LL, 2*n*k-s+1)<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}