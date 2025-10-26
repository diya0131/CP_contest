#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n, i, j, k;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    sort(a, a+n);
    int b=-1;
    for(i=1;i<n;i++){
        if(a[i]%a[0]!=0){
            if(b==-1) b=a[i];
            else{
                if(a[i]%b!=0){
                    cout<<"No"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    

}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}