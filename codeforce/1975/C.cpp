#include<bits/stdc++.h>
#define pb push_back

using namespace std;



void solve(){
    int n, i, j, k;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    if(n==2){
        cout<<min(a[0], a[1])<<endl;
        return;
    }
    int res =0;
    for(i=2;i<n;i++){
        k = a[i]+a[i-1]+a[i-2]-max(a[i], max(a[i-1], a[i-2])) - min(a[i], min(a[i-1], a[i-2]));
        res = max(res, k);
    }
    cout<<res<<endl;

    
    

}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}