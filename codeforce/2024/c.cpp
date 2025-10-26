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

bool comp(pair < int, int> x, pair < int, int > y){
    if(min(x.ff, x.ss)==min(y.ff, y.ss)) return max(x.ff, x.ss)<max(y.ff, y.ss);
    return min(x.ff, x.ss)<min(y.ff, y.ss);
}

void solve() {
    int n, i, j, k, l;
    cin>>n;
    pair < int , int > pr, a[n];
    for(int i=0; i<n; i++){
        cin>>a[i].ff>>a[i].ss;
    }
    sort(a, a+n, comp);
    for(int i=0;i<n;i++){
        cout<<a[i].ff _ a[i].ss<<" ";
    }
    cout<<endl;
    
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}