#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;


void solve(){
    string s, t;
    char k;
    cin>>s>>t;
    k=s[0];
    s[0]=t[0];
    t[0]=k;
    cout<<s<<" "<<t<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}