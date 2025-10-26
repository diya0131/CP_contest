#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define _ <<" "<<
#define ff first
#define ss second
#define test if(te) cout

using namespace std;

const bool te = 1;



void solve() {
    ll n, i, j, k, s;
    cin>>n;
    stack < ll > r;
    queue < ll > l;
    vector < ll > pref(n+1, 0);
    ll sum=0;
    for(i=1;i<=n;i++){
        cin>>k;
        sum+=k;
        pref[i]=sum;
    }
    string str;
    cin>>str;
    for(i=0;i<n;i++){
        if(str[i]=='L'){
            l.push(i+1);
        } else r.push(i+1);
    }
    ll res=0;
    while(!l.empty() && !r.empty() && l.front()<r.top()){
        // test<<pref[r.top()] _ pref[l.front()-1] _ l.front() _ r.top()<<endl;
        res+=pref[r.top()]-pref[l.front()-1];
        r.pop();
        l.pop();
    }
    cout<<res<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}