#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

void solve(){
    ll n, m, k, s, i, x, y;
    cin>>x>>y>>k;
    s=y - x%y;
    while(k>=s && x>1){
        // cout<<k _ s _ y _ x<<endl;
        k-=s;
        x+=s;
        while(x%y==0){
            x/=y;
        }
        s=y - x%y;
    }
    // cout<<k _ x<<endl;
    if(x==1){
        x=(k)%(y-1)+1;
    }
    else x+=k;
    cout<<x<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}