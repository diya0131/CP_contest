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
    ll n, i, j, g, c=0, e, mn=INT_MAX, mx=INT_MIN;
    cin>>n>>g;
    for(i=0;i<n;i++){
        cin>>e;
        if(e<=g){
            c++;
            mx=max(e, mx);
        } else mn=min(e, mn);
    }
    if(g-mx<mn-g){
        cout<<n-c+1 _ g-mx<<endl;
    } else {
        cout<<n-c _ mn-g<<endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1;i <= t;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}