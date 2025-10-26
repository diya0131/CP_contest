
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
    ll n, m, i, j, x, s=0;
    cin>>n;
    ll a[n];
    pair< ll , ll > res[n];
    map < ll , ll > mp;
    bool vis[n];
    for(i=0;i<n;i++){
        vis[i]=0;
        cin>>a[i];
    }
    for(i=n-1;i>=1;i--){
        mp.clear();
        for(j=0;j<n;j++){
            if(!vis[j]){
                if(mp.find(a[j]%i)==mp.end()){
                    mp[a[j]%i]=j;
                } else {
                    res[i]={j, mp[a[j]%i]};
                    vis[j]=1;
                    break;
                }
            }
            
        }
    }
    cout<<"YES\n";
    for(i=1;i<n;i++){
        cout<<res[i].ff+1 _ res[i].ss+1<<endl;
        test<<(a[res[i].ff] - a[res[i].ss]) % i<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}