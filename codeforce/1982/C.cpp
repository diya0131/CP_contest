#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

void solve(){
    ll n, le, ri, l, r, m, x, s, i, j;
    cin>>n>>le>>ri;
    l=0;
    r=0;
    s=0;
    m=0;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        m+=a[i];
        while(m>ri){
            m-=a[l];
            l++;
        }
        if(m>=le){
            s++;
            l=i+1;
            m=0;
        }
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