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
    
    cin>>n>>k;
    if(k==0){
         cout<<0<<endl;
        return;
    }
    if(k<=n) {
        cout<<1<<endl;
        return;
    }
    k-=n;
    j=n-1;
    i=1;
    while(j<=k && j>0){
        test<<"hello" _ j _ k<<endl;
        k-=j;
        if(!(i%2)) j--;
        i++;
    }
    if(k>0) i++;
   cout<<i<<endl;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}