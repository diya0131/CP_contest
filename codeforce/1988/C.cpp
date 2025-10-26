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
    ll n, k, s, q, i, j, m, l;
    cin>>n;
    vector < ll > pow;
    k=n;
    q=1;
    while(k>0){
        if(k%2) pow.pb(q);
        q*=2;
        k/=2;
    }

    if(pow.size()==1){
        cout<<1<<endl<<n<<endl;
        return;
    }
    cout<<pow.size()+1<<endl;
    m=pow.size();
    j=m-1;
    l=m-3;
    for(i=0;i<=m;i++){
        k=n;
        if(j>=0) k-=pow[j];
        if(l>=0) k-=pow[l];
        cout<<k<<" ";
        j--;
        l--;
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}