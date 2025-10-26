#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ALL(a) a.begin(), a.end()
#define test if(te) cout
#define ss second
#define _ <<" "<<

using namespace std;

const bool te = 0;
const ll INF = 1e18;

void solve() {
    ll n, i, j, k, l, r;
    cin>>l>>r;
    k=sqrt(2*(r-l));
    if(k*(k+1)>2*(r-l)) k--;
    // cout<<k<<endl;
    cout<<k+1<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin>>t;
    while (t--) solve();
}