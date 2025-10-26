#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    int n, m, k, i, s=INT_MAX;
    cin>>n;
    cin>>m;
    k=1;
    while(n%2==m%2){
        k*=2;
        n/=2;
        m/=2;
    }
    cout<<k<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}


