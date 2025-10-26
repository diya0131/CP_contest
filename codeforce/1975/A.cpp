#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    int n, i, j, k;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++) cin>>a[i];
    i=1;
    while(i<n && a[i]>=a[i-1]){
        i++;
    }
    if(i==n) cout<<"Yes"<<endl;
    else{
        k = a[i-1];
        i++;
        while(i<n && a[i]>=a[i-1]){
            i++;
        }
        if(i==n && a[n-1]<=a[0]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    

}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}