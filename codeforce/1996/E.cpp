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
const ll M = 1e9+7;

void solve(){
    ll n, k, i, j, x=0, y=0, res=0;
    
    string s;
    cin>>s;
    n=s.size();
    map < ll , ll > mp;
    mp[0]=1;
    for(i=0;i<n;i++){
        // res=(res+(i+1)*(n-i+1)%M)%M;
        if(s[i]=='0') x++;
        else y++;
        if(mp.find(x-y)!=mp.end()){
            test<<mp[x-y] _ res<<endl;
            res=(res+mp[x-y]*(n-i)%M)%M;
        }
        test<<x-y<<endl;
        mp[x-y] += i+2;
    }
    // res=(res+n+1)%M;

    
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}