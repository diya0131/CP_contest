#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

void solve(){
    int a, b, c;
    cin>>a>>b>>c;
    cout<<max(a, max(b, c)) - min(a, min(b, c))<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}