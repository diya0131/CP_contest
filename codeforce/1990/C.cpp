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
    ll n, m, i, j, x, s=0, res=0;
    cin>>n>>x;
    ll a[n], b[n+2];
    for(i=0;i<n;i++) cin>>a[i];
    s=0;
    j=n-1;
    b[n]=0;
    for(i=n-1;i>=0;i--){
        s+=a[i];
        test<<"-- " _ i _ s _ j <<endl;
        if(s<=x) b[i]=b[i+1]+1;
        else {
            while(i<=j && s>x){
                s-=a[j];
                j--;
            }
            test<<i _ j _ b[j+2] _ s<<endl;
            b[i]=j-i+1 + b[j+2];
            
        }
        test<<b[i]<<endl;
        res+=b[i];
        
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