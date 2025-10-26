#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = true;

void solve(){
    ll i, j, s=0, k, t, n,m=0;
    cin>>n>>k;
    test<<n _ k<<endl;
    for(i=0;i<k;i++){
        cin>>k;
        s+=k-1;
        m=max(m, k);
    }
    test<<s _ n _ m<<endl;
    cout<<s+n-2*m+1<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}