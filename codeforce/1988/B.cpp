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
    ll n, i, s=0, su=0;
    cin>>n;
    string str;
    cin>>str;
    if(str[0]=='1') s++;
    else su++;
    for(i=1;i<n;i++){
        if(str[i]=='0'){
            if(str[i-1]=='1') su++;
        } else s++;
    }
    test<<s _ su<<endl;
    if(s>su) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}