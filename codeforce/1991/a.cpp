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

void solve(){
    ll n, k, i, j;
    cin>>n;
    k=0;
    for(i=0;i<n;i++){
        cin>>j;
        if(i%2==0) k = max(k, j);
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