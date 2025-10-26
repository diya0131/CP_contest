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
    ll n, k, res=0;
    cin>>n>>k;
    res=n/(k-1);
    if(k==2){
        cout<<n-1<<endl;
        return;
    }
    if(n%(k-1)>1) res++;
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}