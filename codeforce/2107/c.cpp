#include<bits/stdc++.h>
#include<random>
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const bool TEST = 0;

void solve() {
    ll n, k, s, t, i, j, mx = LLONG_MIN, m=0;
    bool here=false;
    ll mmin = -1;
    for(i=0;i<18;i++) mmin*=10;
    cin>>n>>k;
    string str;
    cin>>str;
    vector< ll > a(n);
    for(i=0;i<n;i++) cin>>a[i];
    s=0;
    for(i=0;i<n;i++){
        if(str[i]=='0'){
            here = 1;
            s=0;
        } else{
            s+=a[i];
            if(s<0) s=0;
        }
        mx = max(mx, s);
    }
    if(mx > k || (mx!=k && !here)) {
        cout<<"No\n";
    } else{
        cout<<"Yes\n";
        if(here){
            for(i=0;i<n;i++){
                if(str[i]=='0') break;
            }
            j=i;
            t=0;
            if(j+1<n && str[j+1]!='0'){
                s=0;
                m=0;
                for(i=j+1;i<n && str[i]=='1';i++){
                    s+=a[i];
                    m=max(m, s);
                }
                t+=m;
            }
            if(j-1>=0 && str[j-1]!='0'){
                s=0;
                m=0;
                for(i=j-1;i>=0 && str[i]=='1';i--){
                    s+=a[i];
                    m=max(m, s);
                }
                t+=m;
            }
            a[j]=k - t;
            str[j]='1';
        }
        for(i=0;i<n;i++){
            if(str[i]=='0'){
                cout<<mmin<<" ";
            } else cout<<a[i]<<" ";
        }
        cout<<endl;
    }

    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}