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
    ll n, k, i, j, x, res=0;
    cin>>n>>x;
    for(i=1;i<n;i++){
        for(j=i;j<(n/i);j++){
            k = min((n-i*j)/(i+j), (x- i - j));
            if(k<j) break;
            if(i==j){
                res+=(k-j)*3+1;
                
            } else {
                res+=(k-j)*6+3;
            }
            test<<k _ i _ j _ res<<endl;
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