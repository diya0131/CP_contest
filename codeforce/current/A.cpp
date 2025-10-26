#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = false;

void solve() {
    ll n, m, k, s, t, i, j;
    char a[5]={'a', 'e', 'o', 'u', 'i'};
    cin>>n;
    k=n/5;
    t=n-k*5;
    for(i=0;i<t;i++){
        for(j=0;j<=k;j++){
            cout<<a[i];
        }
    }
    for(;i<5;i++){
        for(j=0;j<k;j++){
            cout<<a[i];
        }
    }
    cout<<endl;
   
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}