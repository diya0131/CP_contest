#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define test if(te) cout

using namespace std;

const bool te = 0;


void solve() {
    ll l, r, L, R, s, k;
    cin>>l>>r>>L>>R;
    if(min(r, R)<max(l, L)){
        cout<<1<<endl;
        return;
    }
    s=min(r, R)-max(l, L)+2;
    if(l==L) s--;
    if(r==R) s--;
    cout<<s<<endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {

        solve();
    }
}