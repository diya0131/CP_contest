
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
    ll n, m, i, j, x, s=0, c=0, res=0;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n;i++){
        if(a[i]==0) {
            test<< "0 --\n";
            c=0;
            continue;
        }
        test<<c _ a[i]<<endl;
        if(c==0){
            if(a[i]<3){
                c=1;
            } 

            res++;
        } else if(c==1){
            if(a[i]<3){
                c=0;
                continue;
            }
            if(a[i]<5){
                c=2;
            } else {
                c=0;
            }
            res++;
        } else {
            if(a[i]<5){
                c=1;
            } else {
                c=0;
            }
            res++;
        }
        test<<res<<endl;
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