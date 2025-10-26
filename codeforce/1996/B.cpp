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
    char b;
    cin>>n>>k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>b;
            if(i%k==0 && j%k==0){
                cout<<b;
            }
        }
        if(i%k==0)cout<<endl;
    }
    
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}