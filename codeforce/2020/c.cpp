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
    ll a=0, b, c, d, i, s, k, p=1, z=0, b1, c1, d1;
    
    cin>>b>>c>>d;
    b1=b;
    c1=c;
    d1=d;
    while(b>0 || c>0 || d>0){
        // cout<<a _ b _ c _ d<<endl;
        if(b%2){
            if(c%2){
                if(d%2){
                    //
                } else {
                    a+=p;
                }
            } else {
                if(d%2){
                    //
                } else {
                    cout<<-1<<endl;
                    return;
                }
            } 
        } else {
            if(c%2){
                if(d%2){
                    cout<<-1<<endl;
                    return;
                } else {
                    //
                }
            } else {
                if(d%2){
                    a+=p;
                } else {
                    //
                }
            }
        }
        b/=2;
        c/=2;
        d/=2;
        p*=2;
    }
    cout<<a<<endl;
    // cout<<(a | b1) - (a & c1) _ d1<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}