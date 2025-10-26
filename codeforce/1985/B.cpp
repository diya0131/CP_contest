#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;


void solve(){
    ll n, i, j, k, ma=INT_MIN, s=0, res=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
        if(k>ma) ma=k;
        s+=k;
        if(2*ma==s) {
            res++;
        }
    }
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}