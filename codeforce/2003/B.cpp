#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<
#define test if(te) cout

using namespace std;

const bool te = 1;

const ll N = 1e5;

void solve() {
    int n, i, j, s, k;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    sort(a, a+n);
    cout<<a[n/2]<<endl;
}


int main() {
    int t;
    cin >> t;
    while (t--) solve();

}