#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    ll n, i, j, k, s=0, t, ch, ch1;
    cin>>n;
    ll a[n], b[n-1], c[n-2];
    for(i=0;i<n;i++) cin>>a[i];
    for(i=0;i<n-1;i++){
        b[i]=gcd(a[i], a[i+1]);
        
    }
    for(i=0;i<n-2;i++){
        if(b[i]<=b[i+1]) c[i]=1;
        else c[i]=0;
        s+=c[i];
    }
    // cout<<s _ c[0] _ c[n-2]<<endl;
    if(s-c[0]==n-3){
        cout<<"YES"<<endl;
        return;
    }
    if(s-c[n-3]==n-3){
        cout<<"YES"<<endl;
        return;
    }
    for(i=1;i<n-1;i++){
        t=0;
        ch=0;
        ch1=0;
        k=gcd(a[i-1], a[i+1]);
        if(i>1){
            if(b[i-2]>k){
                t=1;
                
            }
            else{
                ch=c[i-2]-1;
            }
           
        }
        
        if(t==0 && i<n-2){
            if(k>b[i+1]){
                t=1;
            }
            else{
                ch1=c[i]-1;
            }
        }
        // cout<<i _ t _ c[i-1] _ ch1 _ ch _ s _  s-c[i-1]-ch1-ch<<endl;
        if(t==0 && s-c[i-1]-ch1-ch == n-3 ){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}


