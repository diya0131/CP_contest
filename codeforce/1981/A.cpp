#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff firts
#define ss second
#define _ <<" "<<

using namespace std;

void solve(){
    ll n, m, x, y, s=0;
    ll l, r;
    cin>>n>>m;
    l = n-m;
    if(l<0) l=0;
    r = n+m;
    ll q=1;
    ll r1 = r, l1 = l;
    while(r>0){
       
        if(l%2){
            s+=q;
        }
        else{
            if((l1/q)*q+q<=r1){
                s+=q;
            }
        }
        r/=2;
        l/=2;
        q*=2;
    }
    cout<<s<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}