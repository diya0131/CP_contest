#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout<<
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = true;

void solve(){
    int a[2], b[2], s=0, i, c;
    cin>>a[0]>>a[1]>>b[0]>>b[1];
    for(int i=0;i<4;i++){
        c=0;
        if(a[i/2]>b[i%2]) c++;
         if(a[i/2]<b[i%2]) c--;
        if(a[0]+a[1]-a[i/2]>b[0]+b[1]-b[i%2]) c++;
         if(a[0]+a[1]-a[i/2]<b[0]+b[1]-b[i%2]) c--;
         if(c>0) s++;
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