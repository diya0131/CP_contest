#include<bits/stdc++.h>
#include<chrono>
#include <random>

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
    ll n, i, j, k, s=0, s1=0, s2=0, st=0;
    cin>>n;
    vector<ll>a, b;
    for(i=0;i<n;i++){
        cin>>k;
        if(k%2) a.pb(k);
        else st+=k;
        s+=k;
    }
    sort(ALL(a));
    if(a.size()>0){
        k=1;
        for(i=1;i<a.size();i++){
            
            if(a[i]==a[i-1]) k++;
            else{
                b.pb(k);
                k=1;
            }
        }
        b.pb(k);
        sort(ALL(b));
        for(i=0;i<b.size();i++){
            if(i%2) s1+=b[i];
            else s2+=b[i];
        }
    }
    k = s1 - s2;
    if(k<0) k=-k;
    cout<< (s+k)/2 _ (s-k)/2<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}