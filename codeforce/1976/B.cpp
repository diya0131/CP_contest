#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    ll n, x, y, i, j;
    cin>>n;
    ll a[n], b[n+1];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<=n;i++){
        cin>>b[i];
    }
    ll res =0, c=2000000000, k=b[n];

    for(i=0;i<n;i++){
        res+=abs(a[i]-b[i]);
        if(a[i]<b[i]){
            if(a[i]<=k && b[i]>=k){
                c=0;
            }
            else{
                if(k>b[i]) c= min( c, (k-b[i]) );
                else c= min( c, (a[i]-k) );
                
            }
        }
        else{
            if(a[i]>=k && b[i]<=k){
                c=0;
            }
            else{
                if(k>a[i]) c= min( c, (k-a[i]) );
                else c= min( c, (b[i]-k) );
                
            }
        }
    }
    cout<<res+c+1<<endl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}