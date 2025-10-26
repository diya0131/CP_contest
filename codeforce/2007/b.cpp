#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ALL(a) a.begin(), a.end()
#define ss second
#define _ <<" "<<

using namespace std;

const bool te = 0;


void solve() {
    ll n, m, i, k, mx=0, l, r;
    cin >> n >> m;
    char ch;
    vector < ll > a(n);
    for (i = 0;i < n;i++) {
        cin>>k;
        mx=max(k, mx);
    }
    
    
    for (i = 0;i < m;i++) {
        cin >> ch >> l >> r;
        if (ch == '+') {
            if(l<=mx && mx<=r) mx++;
        } else {
            if(l<=mx && mx<=r) mx--;
        }
        cout<<mx<<" ";
    }
   
    cout << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}