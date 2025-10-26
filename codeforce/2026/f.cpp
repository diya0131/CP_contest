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

ll M=1e9+7;

void solve() {
    ll n, i, k, s, t, res, a, b, ares=1, bres=0, c=0, p=0;
    cin>>n>>k;
    while(k>1 && n>0){
        a=1;
        b=0;
        do{
            bres=(ares+bres)%M;
            ares=((bres-ares)%M+M)%M;
            b=(a+b)%k;
            a=((b-a)%k+k)%k;
            c=(c+1)%M;
            // cout<<c _ a _ b<<endl;
        }while(b%k);
        n--;
        t=gcd(k,a);
        if(t>1){
            k/=t;
            p=c;
        } else{
            c=(c+((c-p)%M+M)%M*(n%M)%M)%M;
            n=0;
        }
        // cout<<ares _ bres _ n _ k<<endl;
    }
    if(n>0) c+=n;
    cout<<(c%M+M)%M<<endl;
}

int main() {
    // BOOST
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
