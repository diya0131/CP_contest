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
    ll n, k, i, j;
    string s;
    cin>>s;
    n=s.size();
    string res(n+1, ' ');
    res[0]=s[0];
    bool p=true;
    for(i=1;i<n;i++){
        if(s[i-1]==s[i] && p){
            if(s[i-1]=='a') res[i]='b';
            else res[i]='a';
            p=false;
        }
        if(p) res[i]=s[i];
        else res[i+1]=s[i];
    }
    if(p){
        if(s[n-1]=='a') res[n]='b';
        else res[n]='a';
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