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
    ll n, k, i, j, cnt=0;
    cin >> n;
    char a[2][n];
    for(j=0;j<2;j++){
        for(i=0;i<n;i++){
            cin>>a[j][i];
        }
    }
    for(i=1;i<n-1;i++){
        if(a[0][i-1]=='x' && a[0][i]=='.' && a[0][i+1]=='x' && 
            a[1][i-1]=='.' && a[1][i]=='.' && a[1][i+1]=='.') cnt++;
        if(a[1][i-1]=='x' && a[1][i]=='.' && a[1][i+1]=='x' && 
            a[0][i-1]=='.' && a[0][i]=='.' && a[0][i+1]=='.') cnt++;
    }

    cout<<cnt<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}