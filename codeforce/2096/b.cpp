#include<bits/stdc++.h>
#define ll long long
#define ALL(a) a.begin(), a.end()

using namespace std;

void solve(){
    ll n, k, i, s=0, t=0;
    cin>>n>>k;
    vector< ll > left(n), right(n), a(n);
    for(i=0;i<n;i++){
        cin>>left[i];
    }
    for(i=0;i<n;i++){
        cin>>right[i];
    }
    for(i=0;i<n;i++){
        t+=(left[i]+ right[i]);
        s+=max(left[i], right[i]);
        a[i] = min(left[i], right[i]);
    }
    sort(ALL(a));
    for(i=0;i<k-1;i++){
        s+=a[n-1-i];
    }
    // cout<<t - s<<endl;
    cout<<s+1<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}