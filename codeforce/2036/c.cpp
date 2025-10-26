#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define _ << " " <<
#define debug(a) cout << #a << "=" << a << endl;
#define ALL(a) a.begin(), a.end()
#define LLA(a) a.rbegin(), a.rend()
#define BOOST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define test if(TEST) cout

using namespace std;

const bool TEST = 0;

void solve() {
    ll n, i, k, j, t, p, q, all=0;
    string s;
    cin>>s;
    n=s.size();
    for(i=0;i+3<n;i++){
        if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0') all++;
    }
    ll qt;
    cin>>qt;
    while(qt--){
        cin>>k>>t;
        k--;
        p=0;
        for(i=max(0LL, k-3); i<=min(k+3, n-1)-3;i++){
            if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0') p++;
        }
        s[k]='0'+t;
        q=0;
        for(i=max(0LL, k-3); i<=min(k+3, n-1)-3;i++){
            if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0') q++;
        }
        all+=(q-p);
        // cout<< all _ p _ q _ max(0LL, k-3) _ min(k+3, n-1)-3 _ s<<endl;
        if(all) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}