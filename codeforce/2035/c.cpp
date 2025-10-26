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
    ll n, s, k=1, i, a, b, c, p=1, j=1;
    cin>>n;
    if(n%2){
        k=n;
        a=k&(-k);
        c=k-a;
        cout<<k<<endl;
        if(a==1) b=3;
        else b=a-1;
        for(i=1;i<=n;i++){
            if(i!=k && i!=a && i!=b && i!=c) {
                cout<<i<<" ";
                
            }
        }
        cout<<a _ b _ c _ k<<endl;
    }else {
        while(k<=n) k*=2;
        if(k/2==n) {
            k=k-1-n;
            cout<<(n | k)<<endl;
            a=k-1;
            for(i=2;i<n;i++){
                if(i!=a && i!=k) cout<<i<<" ";
            }
            cout<<1 _ a _ k _ n<<endl;
            return;
        }
        else k=(k-1)-n;
        cout<<(k | n)<<endl;
        a=1;
        b=k;
        while(b%2){
            b/=2;
            a*=2;
        }
        a=k+a;
        for(i=1;i<n;i++){
            if(i!=a && i!=k) cout<<i<<" ";
        }
        cout<<a _ k _ n<<endl;
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