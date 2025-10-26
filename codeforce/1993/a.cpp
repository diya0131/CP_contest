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
    ll n, i, j, a[4], res=0;
    cin>>n;
    string s;
    cin>>s;
    for(i=0;i<4;i++) a[i]=n;
    for(i=0;i<4*n;i++){
        if(s[i]!='?'){
            if(a[s[i]-'A']>0){
                a[s[i]-'A']--;
                res++;
            }
        }
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