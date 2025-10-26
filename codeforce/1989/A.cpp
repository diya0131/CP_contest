#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ff first
#define ss second
#define PII pair < int, int >
#define PLL pair < ll, ll >

using namespace std;

void solve(){
    int x, y;
    cin>>x>>y;
    if(-abs(x) > y-abs(x)+1) cout<<"NO\n";
    else cout<<"YES\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}