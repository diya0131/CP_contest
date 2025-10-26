#include<bits/stdc++.h>

#define ll long long 
#define ff first
#define ss second
#define test if(te) cout
#define pb push_back
#define ALL(a) a.begin(), a.end()
#define _ <<" "<<

using namespace std;

const bool te = false;

const ll N = 5001, M = 1e9+7;
ll inv[N];

void calcInv(ll k){
    ll p=M-2, q=k, res=1;
    while(p>0){
        if(p%2){
            res=(res*q)%M;
        }
        q=(q*q)%M;
        p/=2;
    }
    inv[k]=res;
}

ll binom(ll n, ll k){
    test<<"binom " _ n _ k<<endl;
    ll res=1;
    for(ll i=k+1;i<=n;i++){
        res=res*i%M;
        res=res*inv[i-k]%M;
    }
    test<<"res: "<<res<<endl;
    return res;
}


void solve() {
    ll n, i, j, k, p, q, a, b, res=0;
    cin>>n;
    for(k=1;k<=n;k++){
        q=min((n-1)/2, k-1);
        test<<k _ q<<endl;
        if(2*q<k-1) continue;
       
        a=binom(k-1, k-1-q);
        b=binom(n-k, 2*q-k+1);
        // test<<k _ q _ a _ b<<endl; 
        while(true){
            test<<"here" _ k _ q _ a _ b _ a*b <<endl;
            res=(res+(k*a)%M*b%M)%M;
            q--;
            if(2*q<k-1) break;
            test<<inv[(k-1-q)] _ q+1<<endl;
            a=a*inv[k-1-q]%M;
            a=a*(q+1)%M;
            b=b*inv[(n-2*q-2)]%M;//5 - 2 -2 
            b=b*(2*q-k+2)%M;
            b=b*inv[(n-2*q-1)]%M;
            b=b*(2*q-k+3)%M;
            test<<q _ a _ b<<endl; 
        }
    }
    q=binom(n, (n-1)/2);
    for(k=n+1;k<=2*n+1;k++){
        if(k%2){
            q=(q*inv[k/2])%M;
            q=q*(n-k/2+1)%M;
            test<<"last" _ k _ q<<endl;
            res=(res+k*q%M)%M;
        }
    }
    cout<<res<<endl;

}



int main() {
    for(int i=1;i<N;i++){
        calcInv(i);
    }
    inv[0]=0;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}