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
    ll n, i, j, k, s=0, q, s1=0, p=0, pr, nw;
    cin>>n>>q;
    string str;
    vector < ll > a(n), b(n), c(n, 0);
    for(ll i=0; i<n; i++) {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(ALL(b));
    for(i=0;i<n;i++) {
        if(s==s1) c[i]=1;
        s+=a[i];
        s1+=b[i];
        test<<c[i];
    }
    test<<endl;
    cin>>str;
    for(i=1;i<n;i++){
        if(str[i]=='R' && str[i-1]=='L' && c[i]==0) {
            // test<<"fine" _ i _ str[i] _ str[i-1] _ c[i]<<endl;
            p++;
        }
    }
    while(q--){
        cin>>k;
        k--;
        pr=0;
        nw=0;
        test<<str _ k<<endl;
        if(str[k]=='R' && str[k-1]=='L' && c[k]==0) pr++;
        if(str[k+1]=='R' && str[k]=='L' && c[k+1]==0) pr++;
        str[k]='L'+'R'-str[k];
        if(str[k]=='R' && str[k-1]=='L' && c[k]==0) nw++;
        if(str[k+1]=='R' && str[k]=='L' && c[k+1]==0) nw++;
        p+=(nw-pr);
        test<<p _ nw _ pr _ str<<endl;
        if(p==0) cout<<"YES\n";
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