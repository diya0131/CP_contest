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
    ll i, j, s=0, k, t, n, m=0;
    cin>>n>>k;
    for(i=0;i<k;i++){
        cin>>t;
        s+=t-1;
        m=max(m, t);
    }
    cout<<s+n-2*m+1<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}