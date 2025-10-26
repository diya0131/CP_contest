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

int main() {
    ll n, i, j, k, r, d, a;
    cin>>n>>r;
    for(i=0;i<n;i++){
        cin>>d>>a;
        if(d==1){
            if(1600<=r && r<2800) r+=a;
        } else {
            if(1200<=r && r<2400) r+=a;
        }
    }
    cout<<r<<endl;
}