#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<

using namespace std;

void solve(){
    ll n, m, k=1, i, s=0;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
        k=k*a[i]/(gcd(k, a[i]));
    }

    for(i=0;i<n;i++){
        s+=(k/a[i]);
    }
    if(s<k){
        for(i=0;i<n;i++){
            cout<<2*(k/a[i])<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}


