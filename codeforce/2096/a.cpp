#include<bits/stdc++.h>

using namespace std; 

void solve(){
    string s;
    int n, i;
    cin>>n>>s;
    int l=1, r=n;
    vector < int >  res(n);
    for(i=n-2;i>=0;i--){
        if(s[i]=='>') {
            res[i+1]=r;
            r--;
        } else{
            res[i+1] = l;
            l++;
        }
    }
    res[0] = l;
    for(i=0;i<n;i++) cout<<res[i]<<" ";
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}