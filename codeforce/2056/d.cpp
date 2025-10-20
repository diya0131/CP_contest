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

ll lowerbound(vector < ll >& a, ll r, ll k){
    ll l=0, m;
    while(l<r){
        m =(l+r)/2;
        if(a[m]<k) l = m;
        else r = m-1;
    }
}

void solve() {
    ll n, i, j, k, s, cb, cc, res=0;
    cin>>n;
    vector < ll > a(n), b(n, 0), c(n, 0);
    for(i=0;i<n;i++) cin>>a[i];
    for(k=1;k<=10;k++){
        cb=0;
        cc=0;
        for(i=0;i<n;i++){
            if(a[i]>k) cb--;
            if(a[i]<k) cc--;

            //search
            j = upper_bound(a.begin(), a[2],3) - a[0];
            cc++;
            cb++;
        }

    }
    
}

int main() {
    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
    vector < int > a(10);
    for(int i=0;i<10;i++) a[i]=i;
    cout<<*lower_bound(a.begin(), a.begin()+3, 10)<<endl;
}