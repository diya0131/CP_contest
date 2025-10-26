#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ppb pop_back
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ff first
#define ss second
#define PLL pair < ll, ll >

using namespace std;


void solve() {
    ll n, k, i, s=0;
    cin >> n ;
    ll a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    k=0;
    for(i=n-1;i>=0;i--){
        if(a[i]>k){
            s+=a[i]-k;
            k=a[i];
        }
        else{
            if(a[i]==k) k++;
            s++;
        }
        
    }
    cout<<s<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}